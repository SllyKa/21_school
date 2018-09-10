#!/bin/sh

rm -f test_result standard

echo "Testing..."
make re > /dev/null

./eval_expr "3 + 42 * (1 - 2 / (3 + 4) - 1 % 21) + 1" >> test_result
echo "4"  >> standard
./eval_expr "2 + 2" >> test_result
echo "4" >> standard
./eval_expr "2 + 2 + 2" >> test_result
echo "6" >> standard
./eval_expr "3 + 2 * 2" >> test_result
echo "7" >> standard
./eval_expr "3 + 3 * 3 + 3" >> test_result
echo "15" >> standard
./eval_expr "3 + 3 * 3 * 3" >> test_result
echo "30" >> standard
./eval_expr "3 + 3 * (3 + 3 * (3 + 3 * 3 + 3 * (3 + 3)))" >> test_result
echo "282">> standard
./eval_expr "3 + 3 * 3 * (3 + 3 * (3 + 3 * 3 + 3 * (3 + 3)))" >> test_result
echo "840" >> standard
./eval_expr "2 - (2 + 5)" >> test_result
echo "-5" >> standard
./eval_expr "2 - 2 + 5" >> test_result
echo "5" >> standard
./eval_expr "10 % -20" >> test_result
echo "10" >> standard
./eval_expr "-10 % -20" >> test_result
echo "-10" >> standard
./eval_expr "-10 % 20" >> test_result
echo "-10" >> standard
./eval_expr "5/6" >> test_result
echo "0" >> standard
./eval_expr "6" >> test_result
echo "6" >> standard
./eval_expr "-6 + 7" >> test_result
echo "1" >> standard
./eval_expr "(19 - (12 + 7)) * (735 - 7365 + 0)" >> test_result
echo "0" >> standard
./eval_expr "2*2*2*2" >> test_result
echo "16" >> standard
./eval_expr "100/-5" >> test_result
echo "-20" >> standard
./eval_expr "2 * (-15)" >> test_result
echo "-30" >> standard
./eval_expr "2 + ((2 * 2))" >> test_result
echo "6" >> standard
./eval_expr "30+6*(13-9)" >> test_result
echo "54" >> standard
./eval_expr "-1" >> test_result
echo "-1" >> standard
./eval_expr "(-1)" >> test_result
echo "-1" >> standard
./eval_expr "((-1))" >> test_result
echo "-1" >> standard
./eval_expr "((((((((((15))))))))) + (5))" >> test_result
echo "20" >> standard

echo "Checking diff..."
diff -U 3 test_result standard
echo "Testing finished."
