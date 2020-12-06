
#rm -rf output
#mkdir output
#rm -rf plots
#mkdir plots

for I in $(node -p "for(let i = 30; i <= 31; i += 0.5) { console.log(i.toFixed(5)) }")
do
	bin/one_neuron "${I}" 15000 0.01 "output/${I}.csv"
  gnuplot -e "set datafile separator ','; set title 'Зависимость потенциала действия мембраны x от времени t'; set terminal png size 1280, 460; set ylabel 'x(t)'; set xlabel 't'; set output 'plots/${I}.png'; plot 'output/${I}.csv' using 1:2 with lines lw 2 lt rgb 'blue' title 'x(t), I = ${I}'; "
done
