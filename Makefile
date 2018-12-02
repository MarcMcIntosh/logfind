CFLAGS = -Wall -g

.logfind:
	$(shell echo "README.md" > $@)
	$(shell echo "CHANGELOG.md" >> $@)


all: clean .logfind logfind 

logfind: logfind.c 
	cc $(CFLAGS) $^ -o $@

clean:
	if [ -f logfind ]; then rm logfind; fi
	if [ -f .logfind ]; then rm .logfind; fi

