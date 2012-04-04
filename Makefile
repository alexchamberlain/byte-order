

test_byte_order: test_byte_order.cpp byte-order.h
	g++ -O3 -o $@ $<

test_byte_order.s: test_byte_order.cpp byte-order.h
	g++ -O3 -S $<
