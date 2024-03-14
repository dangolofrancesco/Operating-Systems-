target:
	#ES1 sort t.txt -nr -k1,1
	#ES2 sort t.txt -k2,2
	#ES3 grep t.txt -e "2011-2012" 
	#ES4 grep -e "INF1T3" t.txt | sort -n -k1,1
	#ES5 egrep -e "^[0-9]*[24]\> " t.txt | sort -k2,2
	#ES6 grep -e "TLC1T3"  t.txt | grep -e "Da frequentare" | sort -rn -k1,1
	#ES7 grep  "A..A" t.txt
	#ES8 egrep -e "A..A" t.txt | egrep -v "\<A" | egrep -v "A\>"
	#ES9 cut -d " " -f1,1 t.txt | tr -d 0 | tr 8 1 | sort -n | uniq 
	#ES10 cut -d " " -f1,1 t.txt | tr -d 0 | tr 8 1 | sort -n | uniq -d 
