data_targets = radios.dat

PuntoNemo.pdf : radios.dat
	python plots.py && rm *.dat *.x

$(data_targets) : a.x
	./a.x

a.x : PuntoGeographicPoint.c
	cc PuntoGeographicPoint.c -lm -o a.x

