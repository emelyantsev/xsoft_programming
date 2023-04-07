FILES = logserver logclient logviewer

all : ${FILES}

logserver: logserver.c
	gcc $^ -g -o $@ -lpthread

logclient: logclient.c
	gcc $^ -g -o $@

logviewer: logviewer.c
	gcc $^ -g -o $@

clean :
	rm -f ${FILES}