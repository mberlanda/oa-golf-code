#!/usr/bin/env bash

export EXCERCISE=$1
export TESTCASES_DIR="${EXCERCISE}-testcases"
export TESTCASES=()

function compile() {
  gcc "${EXCERCISE}.c" -o $EXCERCISE
}

function load_inputs(){
  for file in $(find "${TESTCASES_DIR}/input" -type f)
  do
    TESTCASES+=(`basename $file`)
  done
}

function trim(){
  echo $(echo $1 | sed -e 's/^[[:space:]]*//')
}

function main(){
    compile
    load_inputs
    for input in "${TESTCASES[@]}"
    do
    local input_file="$TESTCASES_DIR/input/$input"
    local output=${input/input/output}
    local output_file="$TESTCASES_DIR/output/$output"
    local result=$(trim $(cat ${input_file} | ./$EXCERCISE))
    local expected=$(trim $(cat $output_file))

    if [[ ! -z ${OUTPUT_PATH+x} ]]; then
      result=$(trim $(cat $OUTPUT_PATH))
    fi

    if [[ $result == $expected ]]; then
      echo "${input} passed"
    else
      echo "${input} did not pass"
      echo "Expected: ${expected}"
      echo "Got: ${result}"

      exit 1
    fi
    done
}

main
