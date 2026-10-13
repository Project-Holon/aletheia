/*
 * function: WIFICLUBACTOR_CreateCursorActors
 * address:  0x021B9DF4
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIFICLUBACTOR_CreateClactActors  0x021B9EB8  thumb
 *
 * Tail call thunk onto WIFICLUBACTOR_CreateClactActors.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern void WIFICLUBACTOR_CreateClactActors(void *a, int b);

void WIFICLUBACTOR_CreateCursorActors(void *a, int b)
{
    WIFICLUBACTOR_CreateClactActors(a, b);
}
