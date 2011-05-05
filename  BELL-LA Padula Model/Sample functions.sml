(*The BELL-LA Padula Model*)
(*The program will reference states called q0...q3 these are the 4 states that a user can be in*)
(*q0->public, q1->Limited, q2->Secret, q3->top secret*)


(*By default the user is NULL or unauthorized.*)
val user="NULL"; 

(*type in username and password*)
print "Username: \n";
val username=(TextIO.input(TextIO.stdIn):string);
print "Password: \n";
val password=(TextIO.input(TextIO.stdIn):string);


(*user login. Might create encrypted passwords/usernamed file storage later*)
fun login_user("q0\n","q0\n")="q0"
	|login_user("q1\n", "q1\n")="q1"
	|login_user("q2\n", "q2\n")="q2"
	|login_user("q3\n", "q3\n")="q3"
	|login_user(_)="NULL";




val user=let
	val temp = print "type in username: ";
	val username=(TextIO.input(TextIO.stdIn):string);
	val temp = print "type in password: ";
	val password=(TextIO.input(TextIO.stdIn):string);
	in
	login_user(username,password)
	end


(*val user=login_user("public","public");*)
(*val user="q0"*);
print(user^"\n");

(*help option*)
val help = print("These are your options in using the system: \n L=Login again R=List Readable files \n W=List Writeable Files \n I=Info for your security clearance \n C=Create new file instance \n");

(*creates a list version of read FSM*)
(*simple security property*)
fun read_fda("q0",[])= "q0"::[]
	|read_fda("q1",[])="q1"::[]
	|read_fda("q2",[])="q2"::[]
	|read_fda("q3",[])="q3"::[]
	|read_fda("q0","r"::rx)=read_fda("q0",rx)
	|read_fda("q1","r"::rx)=read_fda("q0",rx) @ read_fda("q1",rx)
	|read_fda("q2","r"::rx)=read_fda("q0",rx) @ read_fda("q1",rx) @ 		read_fda("q2",rx)
	|read_fda("q3","r"::rx)=read_fda("q0",rx) @ read_fda("q1",rx) @ 		read_fda("q2",rx) @ read_fda("q3",rx)
	|read_fda(_)="ERROR STATE"::[];

(*creates a list version of write FSM*)
(*The star proerty*)
fun write_fda("q0",[])="q0"::[]
	|write_fda("q1",[])="q1"::[]
	|write_fda("q2",[])="q2"::[]
	|write_fda("q3",[])="q3"::[]
	|write_fda("q0","w"::wx)=write_fda("q0",wx) @ write_fda("q1",wx) @ 			write_fda("q2",wx) @ write_fda("q3",wx)
	|write_fda("q1","w"::wx)=write_fda("q1",wx) @ write_fda("q2",wx) @ 			write_fda("q3",wx)
	|write_fda("q2","w"::wx)=write_fda("q2",wx) @ 				write_fda("q3",wx)	
	|write_fda("q3","w"::wx)=write_fda("q3",wx)
	|write_fda(_)="ERROR STATE"::[];

(*sample read/write states given the user. At login, the value for the 1st tuple will be the permission set. In this example, the Top_secret user has login*)
val read_states = read_fda(user,["r"]);
val write_states= write_fda(user,["w"]);


(* given a set of states, if the file has the permissions in the state list, return true, otherwise false.*)
fun find([],y)=false
	|find(r::rx,y)=if(r=y)then true else find(rx,y);


(*Example: can file that has public access be read by a person with "read states" permissions? Should be true.*)
find(read_states,"q0");


(*sample files with a name F# and a the permission level*)
val files = [["F1","q0"],["F2","q1"],["F3","q2"],["F4","q3"],["F5","q0"],["F6","q1"],["F7","q2"],["F8","q3"],["F9","q0"],["F10","q1"],["F11","q0"],["F12","q1"],["F13","q2"],["F14","q3"],["F15","q0"],["F16","q1"],["F17","q2"],["F18","q3"],["F19","q0"],["F20","q1"],["F21","q0"],["F22","q1"],["F23","q2"],["F24","q3"],["F25","q0"],["F26","q1"],["F27","q2"],["F28","q3"],["F29","q0"],["F30","q1"],["F31","q0"],["F32","q1"],["F33","q2"],["F34","q3"],["F35","q0"],["F36","q1"],["F37","q2"],["F38","q3"],["F39","q0"],["F40","q1"],["F41","q0"],["F42","q1"],["F43","q2"],["F44","q3"],["F45","q0"],["F46","q1"],["F47","q2"],["F48","q3"],["F49","q0"],["F50","q1"]];


fun files_write([])=[]
	|files_write([x,y]::xs)=if(find(write_states,y)) then x::(files_write(xs)) else files_write(xs)
	|files_write(_)="ERROR"::[];
fun files_read([])=[]
	|files_read([x,y]::xs)=if(find(read_states,y)) then x::(files_read(xs)) else files_read(xs)
	|files_read(_)="ERROR"::[];

(*Sample functionality to create a list of files that the user can read and write*)
files_write(files);
files_read(files);

fun create_file(filenam, userpermissions,orig)=orig @ [filenam,userpermissions]::[];

val files=create_file("F51",user,files);


fun commands("quit\n")=print("quiting")
	|commands("L\n")=print( user "Login again:")
	|commands("R\n")=print("Read files:")
	|commands("W\n")=print("Write files:")
	|commands("I\n")=print("Security clearance:")
	|commands("C\n")=print("Security clearance:");
