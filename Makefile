execute:
	g++ notify.cpp -o notify `pkg-config --cflags --libs libnotify` && ./notify
clean:
	rm ./notify
