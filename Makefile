default: 
	cc -Wall -Wextra -ggdb src/*.c -o termux-font-installer

test:
	gcc test/*.c -o termux-font-installer -lcurl
