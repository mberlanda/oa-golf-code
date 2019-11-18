#!/usr/bin/env bash

export EXCERCISE=$1
export TESTCASES_DIR="${EXCERCISE}-testcases"
export TESTCASES=()

function compile() {
  gcc "${EXCERCISE}.c" -o $EXCERCISE
}

function load_inputs(){
  for file in "${TESTCASES_DIR}/input/*"
  do
    TESTCASES+=(`basename $file`)
  done
}

function main(){
    compile
    load_inputs
    for input in "${TESTCASES[@]}"
    do
    local input_file="$TESTCASES_DIR/input/$input"
    local output=${input/input/output}
    local output_file="$TESTCASES_DIR/output/$output"
    local result=$(cat ${input_file} | ./$EXCERCISE)
    if [[ $result == $(cat $output_file) ]]; then
      echo "${input} passed" 
    else
      echo "${input} did not pass"
      exit 1
    fi
    done
}

main