default: 
	cc -Wall -Wextra -ggdb src/*.c -o termux-font-installer

testfile:
	gcc test/*.c -o termux-font-installer -lcurl