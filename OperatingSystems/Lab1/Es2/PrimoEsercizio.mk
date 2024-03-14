target:
	whoami #to get my username
	groups ${whoami} #to know which groups belongs to the current user
	echo ~
	#tree ~
	ls -la #to show access rights 
	chmod 000 PrimoEsercizio.mk 
	chmod a+rw PrimoEsercizio.mk #two ways to change the permissions of the current file