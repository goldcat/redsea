# redsea changelog

## 0.7.4 (xxxx-xx-xx)

* Add support for 15B groups (Fast basic tuning and switching information)
* Add support for "speech/music" flag
* Add support for TMC Other Network info
* Change JSON booleans from strings ("true") to plain booleans (true)
* Change JSON format of all TMC location table and service ID numbers from hex
  strings ("0x1F") to plain numbers (31)

## 0.7.3 (2016-09-20)

* Compile all TMC text data in to the executable - no external files (#26)
* Add compile-time flag to disable TMC support, as the above can take some time
* Add option `-u` to use North American (RBDS) program type names
* Fix TMC message not showing until the next one is received (#21)
* Fix spelling of program type names (no title case or 16-character limit)
* Fix high error rate in the beginning of reception by increasing AGC bandwidth
* Change format of alternate frequencies from string to numbers
* Change format of TMC location table number from hex string to number

## 0.7.2 (2016-09-18)

* Apply burst error correction to check bits as well
* Fix off-by-one errors in RadioText+ caused by RT characters being converted to
  UTF-8, thanks flux242
* Fix most cases of RadioText+ fields containing segments from a previous RT
  message
* Fix bogus {"pi":"0x0000"} printout at EOF
* Don't print empty or incomplete TMC messages
* Use "debug" JSON object instead of C-style comments for debug information
* Warn if TMC data files couldn't be opened

## 0.7.1 (2016-09-17)

* Fixed broken JSON output in 3A groups, thanks flux242

## 0.7.0 (2016-09-16)

* First numbered release!