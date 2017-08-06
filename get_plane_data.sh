#!/bin/bash

get_all_planes() {
	curl -s 'https://data-live.flightradar24.com/zones/fcgi/feed.js?bounds=90,-90,-180,180&faa=0&mlat=0&flarm=0&adsb=0&gnd=0&air=1&vehicles=0&estimated=0&maxage=7200&gliders=0&stats=0&selected=e608abb&ems=0' \
		-H 'Accept: application/json, text/javascript, */*; q=0.01' -H 'Accept-Language: en-US,en;q=0.5' --compressed -H 'Connection: keep-alive' -H 'Pragma: no-cache' -H 'Cache-Control: no-cache' \
			| sed -rn '/:\[/s/.*"(.*)":\[.*/\1/p'
#| grep -o '"[^"]*":\[.*\]'
}

get_plane_trail() {
	curl -s "https://data-live.flightradar24.com/clickhandler/?version=1.5&flight=$1" \
		-H 'Accept: application/json, text/javascript, */*; q=0.01' -H 'Accept-Language: en-US,en;q=0.5' --compressed -H 'DNT: 1' -H 'Connection: keep-alive' \
			| sed -r 's/.*"trail":\[([^]]*)\].*/\1/' \
			| sed 's/},/\n/g' \
			| sed -r 's/.*"lat":([^,]*),"lng":([^,]*).*/\1 \2/g'
}

get_all_planes | while read plane_id; do
	get_plane_trail $plane_id

	break # work with one plane for now
done
