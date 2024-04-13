set -e

CodeChecker analyze ./build/compile_commands.json --enable sensitive --output ./build/reports
CodeChecker parse ./build/reports -e html -o ./build/reports_html