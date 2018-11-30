CFLAGS = -Wall -g

.logfind:
	$(shell cat README.md CHANGELOG.md > $@)                                                                         
                                       

all: clean .logfind logfind 

logfind: logfind.c 
	cc $(CFLAGS) $^ -o $@

clean:
	if [ -f logfind ]; then rm logfind; fi
	if [ -f .logfind ]; then rm .logfind; fi

