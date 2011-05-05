(*The BELL-LA Padula Model*)
(*The program will reference states called q0...q3 these are the 4 states that a user can be in*)
(*q0->public, q1->Limited, q2->Secret, q3->top secret*)

(*HELPER FUNCTIONS*)

(*sample files with a name F# and a the permission level*)
val files = [["F1","q0"],["F2","q1"],["F3","q2"],["F4","q3"],["F5","q0"],["F6","q1"],["F7","q2"],["F8","q3"],["F9","q0"],["F10","q1"],["F11","q0"],["F12","q1"],["F13","q2"],["F14","q3"],["F15","q0"],["F16","q1"],["F17","q2"],["F18","q3"],["F19","q0"],["F20","q1"],["F21","q0"],["F22","q1"],["F23","q2"],["F24","q3"],["F25","q0"],["F26","q1"],["F27","q2"],["F28","q3"],["F29","q0"],["F30","q1"],["F31","q0"],["F32","q1"],["F33","q2"],["F34","q3"],["F35","q0"],["F36","q1"],["F37","q2"],["F38","q3"],["F39","q0"],["F40","q1"],["F41","q0"],["F42","q1"],["F43","q2"],["F44","q3"],["F45","q0"],["F46","q1"],["F47","q2"],["F48","q3"],["F49","q0"],["F50","q1"]];

(* given a set of states, if the file has the permissions in the state list, return true, otherwise false.*)
fun find([],y)=false
	|find(r::rx,y)=if(r=y)then true else find(rx,y);


fun login_user("public\n","public\n")="q0"
	|login_user("limited\n", "limited\n")="q1"
	|login_user("Secret\n", "Secret\n")="q2"
	|login_user("Top Secret\n", "Top Secret\n")="q3"
	|login_user(_)="NULL";

fun user_permissions("q0")="public"
	|user_permissions("q1")="limited"
	|user_permissions("q2")="Secret"
	|user_permissions("q3")="Top Secret"
	|user_permissions(_)="NULL";

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

(*By default user has not logged in*)
val user="NONE";

(*MAIN FUNCTION*)

fun commands("quit\n",user,files)="quiting"
	|commands("L\n",user,files)=
		let 
		val temp = print "type in username: ";
		val username=(TextIO.input(TextIO.stdIn):string);
		val temp = print "type in password: ";
		val password=(TextIO.input(TextIO.stdIn):string);
		in
		commands("Redo",login_user(username,password),files)
		end
	|commands("R\n",user,files)=
		let 
		val read_states = read_fda(user,["r"]);
		fun files_read([])="\n"
			|files_read([x,y]::xs)=if(find(read_states,y)) then x^", "^(files_read(xs)) 					else files_read(xs)
			|files_read(_)="ERROR";
		val temp=files_read(files);
		val tempw=print temp;
		in
		commands("Redo",user,files)
		end		
	|commands("W\n",user,files)=
		let
		val write_states= write_fda(user,["w"]);
		fun files_write([])="\n"
		|files_write([x,y]::xs)=if(find(write_states,y)) then x^", "^(files_write(xs)) else 			files_write(xs)
		|files_write(_)="ERROR"; 
		val temp=files_write(files);
		val tempw=print temp;
		in
		commands("Redo",user,files)
		end
	|commands("I\n",user,files)=
		let
		val temp="User permissions: "^ user_permissions(user) ^"\n";
		val tempp=print temp;
		in
		commands("Redo",user,files)
		end
	|commands("C\n",user,files)=
		let
		val temp="Enter File name: ";
		val filenam_new=(TextIO.input(TextIO.stdIn):string);
		val filenam_new = substring(filenam_new,0,size(filenam_new)-1);
		fun create_file(filenam, userpermissions,orig)=orig @ [filenam,userpermissions]::[];
		val new_files = create_file(filenam_new, user, files) 
		in
		commands("Redo",user,new_files)
		end	
	|commands("Redo",user,files)=
		let
		val temp = print "type in command: ";
		val temp = (TextIO.input(TextIO.stdIn):string);
		in
		commands(temp,user,files)
		end
	|commands("H\n",user,files)= 
		let val temp = print "These are your options in using the system: \n L=Login again R=List Readable files \n W=List Writeable Files \n I=Info for your security clearance \n C=Create new file instance \n";
		in
		commands("Redo",user,files)
		end
	|commands(_)="Invalid command. Quiting\n";
			
print "Type command. To find available commands type H. \n";
print(commands(TextIO.input(TextIO.stdIn):string, user,files )^"\n");
