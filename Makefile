CFLAGS = -Wall -g

.logfind:
	$(shell echo "*.md" > $@)


all: clean .logfind logfind 

logfind: logfind.c 
	cc $(CFLAGS) $^ -o $@

clean:
	if [ -f logfind ]; then rm logfind; fi
	if [ -f .logfind ]; then rm .logfind; fi

