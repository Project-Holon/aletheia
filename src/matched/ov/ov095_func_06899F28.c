/*
 * unit: yes
 * function: func_06899F28, func_06899F40
 * address: 0x06899F28
 * packet: pkt_ov095_06899F28
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_06899E68 0x06899E68 thumb ov095
 *   func_06899E48 0x06899E48 thumb ov095
 *   func_0689A988 0x0689A988 thumb ov095
 *   func_0689A878 0x0689A878 thumb ov095
 * Unlabelled setter follower at 06899F40 lies inside the handed extent.
 */
#include "../include/Obj07912.h"
#include "../include/Obj21889.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct Slot { int (*f0)(void *,int); int (*f1)(void *,int); int arg; int data; } Slot;
typedef struct Q { u8 pad[0x20]; Slot tab[4]; int n; } Q;
extern int func_06899E68(Q *);
extern void func_06899E48(void *,void *,void *);
extern int func_0689A988(int,u8 *);
extern int func_0689A878(int,u8 *);
u32 func_06899F28(u8 *p) {
 if(func_06899E68((Q *)p)) return ((struct Obj21889 *)p)->f98;
 return 0;
}
void func_06899F40(u8 *p, void *a, void *b) {
 ((struct Obj07912 *)p)->f6C=a;
 ((struct Obj07912 *)p)->f70=b;
 ((struct Obj07912 *)p)->f98=0;
 ((struct Obj07912 *)p)->f68=(void *)func_0689A988;
 func_06899E48(p,(void *)func_0689A878,(void *)func_0689A988);
}
