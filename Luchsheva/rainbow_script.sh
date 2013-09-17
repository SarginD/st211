#!/bin/bash
dir_list=( kagdui ohotnik gelaet znat gde sidit fazan )
file_list=( krasnui orangevui geltui zelenui goluboi siniy fioletovui )
phras_list=( Hi, my script was done very well )
rm -r rainbow
mkdir rainbow
cd rainbow
nomer=0
for i in "${dir_list[@]}"
do 
    mkdir $i
    touch ./${i}/${file_list[$nomer]}
    echo ${phras_list[$nomer]} > ./${i}/${file_list[$nomer]}
    nomer=$(( $nomer + 1 ))
done
for j in "${dir_list[@]}"
do
    var=$( ls ./${j} | grep "^g")
      if [[ $var = "" ]]
      then    
        rm -r ${j}
      fi
done
cat ge*/* gd*/*
