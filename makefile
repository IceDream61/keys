readme : put_token put get make_readme
	./make_readme
make_readme : make_readme.c put_token.c put.c get.c
	gcc -w make_readme.c -o make_readme
put_token : put_token.c cryption.h input_token.h
	gcc -w put_token.c -o put_token
put : put.c cryption.h input_token.h
	gcc -w put.c -o put
get : get.c cryption.h input_token.h
	gcc -w get.c -o get

clean :
	rm put_token put get make_readme readme *.txt
