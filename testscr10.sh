#!/bin/bash
declare -i nr_params=$#

if [ $nr_params -gt 0 ]
then
	fname=$1

	gcc ./maingen.c -o maingen
	gcc $fname -o exelab
	
	listfiles=$(ls ./tests)
	
	declare -i cnt=1

	for i in $listfiles
	do

	./maingen
	cat ./generatedMain > ./generatedMains/$cnt
	sleep 1
	gcc ./scheletOP.c -o scheletOP
	echo -ne "Test $cnt: \n"

	./exelab ./tests/$i > outputstud
	./scheletOP ./tests/$i > outputschelet

	declare -i index=1

		while read line_output
		do
				for (( j=1;j<=$index;j++ ))
				do
						read line_result
				done < outputstud


				if [[ "$line_output" = "$line_result" ]]
				then
						echo "Right call of function."
				else 
						echo "Wrong call of function. Problem near line $index."
				fi

				index+=1
		done < outputschelet
	

	cnt+=1

	done

else
        echo "trimite sursa ca parametru!"
        exit -1
fi
