RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color

for f in ./../players/*.filler
do
	for m in ./../maps/map*
	do
		let "count = 0"
		for n in `seq 1 5`
		do
			./../filler_vm -q -p1 ./../*.filler -p2 "$f" -f "$m" > quiet
			line=`grep won filler.trace`
			echo "$line"
			if [ "$line" = './../cholm.filler won' ];
			then let "count = $count + 1"
			fi
		done
		for n in `seq 1 5`
		do
			./../filler_vm -q -p2 ./../*.filler -p1 "$f" -f "$m" > quiet
			line=`grep won filler.trace`
			echo "$line"
			if [ "$line" = './../cholm.filler won' ];
			then let "count = $count + 1"
			fi
		done
		let "win = 0"
		let "win = ($count * 100) / 10"
		if [ $win -ge 50 ];
		then echo ${GREEN}$win % of win against $f on map $m${NC}
		else
			echo ${RED}$win % of win against $f on map $m${NC}
		fi
	done
done
