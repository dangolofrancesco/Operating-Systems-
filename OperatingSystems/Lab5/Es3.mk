target:
	#1ES find / -name "*.exe" -executable -size +1024c
	#2ES find . -name "*.c" -size +100c
	#3ES  find . -type f -regextype -posix-extended -regex "(.*a.*A) | (.*A.*a)" -exec tail -n 3 \{} \;
	#4ES find . -type f -maxdepth 5 -mindepth 3 -size +250c -regextype -posix-extended -regex ".*\/...." -exec wc -ml \{} \; 
	#5ES find / -type f -regex ".*(\/A.*zzz.*\....)$" -exec tar czvf \{}.tar.gz \{} \;
	#6ES find / -name "bin" -type d -exec ls \{} \; 
	#7ES find . -type f -name "*.c" ! -user brunobryan  -group test
	#8ES find / -type -f -maxdepth 1 -user brunobryan -exec chmod go-wre \{} \; 

