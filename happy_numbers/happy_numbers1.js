var fs  = require("fs");
fs.readFileSync(process.argv[2]).toString().split('\n').forEach(function (line) {
    if (line != "") {
      if (line == 1) {
        console.log(line);
      } else {
        console.log(happyNumber(line));
      }
    }
});

function happyNumber(number) {
  var numbers = [],
    stringNumber,
    i = 0,
    acc = 0
    currentNumber = number,
    newNumber = "";

  while(true) {
    acc = 0;
    newNumber = "";
    stringNumber = currentNumber + "";

    for (i = 0; i < stringNumber.length; i++) {
      newNumber += stringNumber[i];
      acc += stringNumber[i] * stringNumber[i];
    }

    if (acc == 1) {
      return 1;
    } else {
      currentNumber = acc;

      if (numbers.indexOf(acc) != -1) {
        return 0;
      }

      numbers.push(acc);
    }
  }
}
