ps x|awk '{ for (x=5; x<=10; x++) {  printf "%s", $x; if (x==10) printf"\n"; } }'

