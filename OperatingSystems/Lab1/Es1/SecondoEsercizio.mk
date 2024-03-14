target:
	cd ./osEx01/src && \
	cp lab01e01in.txt ../test/results && \
	cp lab01e01in.txt ../test && \
	cp lab01e01in.txt ../test/script
	
	#see the content of the file
	cat ./osEx01/src/lab01e01in.txt
	#more ./osEx01/src/lab01e01in.txt
	#less ./osEx01/src/lab01e01in.txt
	diff ./osEx01/src/lab01e01in.txt ./osEx01/test/results/lab01e01in.txt
	
	cd ./osEx01/src && \
	rm -f  ../test/lab01e01in.txt  ../test/script/lab01e01in.txt ../test/results/lab01e01in.txt