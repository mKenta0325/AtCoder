"use strict";

const main = arg => {
  const input = arg.trim().split("\n");

  const N = parseInt(input[0].split(" ")[0]);
  const K = parseInt(input[0].split(" ")[1]);
  const A = input[1].split(" ").map(n=>parseInt(n));
}
main(require('fs').readFileSync('/dev/stdin', 'utf8'));  
