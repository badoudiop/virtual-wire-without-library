tx send 3 unsigned chars , rx receive and display .
tx_uint24 send a number with 3 chars (24 bits) from msb ->midle->lsb  ; 
rx_uint24 receive them and create the number sent .
uint24_t does not exists so you get a number as an uint32_t ; 
uint24_t is from 0 to 166,777,215