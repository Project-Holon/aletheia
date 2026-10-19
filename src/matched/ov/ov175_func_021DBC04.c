/*
 * function: WIFIBATTLEMATCH_NET_SetupGdbUpload
 * address: 0x021DBC04
 * packet: pkt_ov175_021DBC04
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFIBATTLEMATCH_NET_LookupFieldEntry 0x021DD044 thumb ov175
 *   WIFIBATTLEMATCH_NET_GetDateTime 0x021DA470 thumb ov175
 *   WIFIBATTLEMATCH_NET_SetupGdbRecord 0x021DB6A8 thumb ov175
 *   func_02034714 0x02034714 arm
 *   _u32_div_f 0x0209C2B0 arm
 *   d_021E2EF8 0x021E2EF8 data a4
 *   d_021E2F8C 0x021E2F8C data a4
 *   d_021E2F38 0x021E2F38 data a4
 *   d_021E2DF8 0x021E2DF8 data a4
 *   d_021E2F7C 0x021E2F7C data a4
 */
#include "../include/Obj00312.h"
#include "../include/Obj24359.h"
#include "../include/Obj24360.h"
#include "../include/Obj24361.h"
#include "../include/Obj24362.h"
#include "../include/Obj24363.h"
#include "../include/Obj24364.h"
#include "../include/Obj24365.h"
#include "../include/Obj24366.h"
#include "../include/Obj24367.h"
#include "../include/Obj24368.h"
#include "../include/Obj24369.h"
#include "../include/Obj24370.h"
#include "../include/Obj24371.h"
#include "../include/Obj24372.h"
#include "../include/Obj24373.h"
#include "../include/Obj24374.h"
#include "../include/Obj24375.h"
#include "../include/Obj24376.h"
#include "../include/Obj24377.h"
#include "../include/Obj24378.h"
#include "../include/Obj24379.h"
#include "../include/Obj24380.h"
#include "../include/Obj24381.h"
#include "../include/Obj24382.h"
#include "../include/Obj24383.h"
#include "../include/Obj24384.h"
#include "../include/Obj24385.h"
#include "../include/Obj24386.h"
#include "../include/Obj24387.h"
#include "../include/Obj24388.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct Record {u32 words[21];};
extern int WIFIBATTLEMATCH_NET_LookupFieldEntry(int);
extern void WIFIBATTLEMATCH_NET_GetDateTime(u8 *);
extern void WIFIBATTLEMATCH_NET_SetupGdbRecord(char *);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern const u8 d_021E2EF8[],d_021E2F8C[],d_021E2F38[],d_021E2F7C[];
extern const u32 d_021E2DF8[];
void WIFIBATTLEMATCH_NET_SetupGdbUpload(u8 *p,u32 mode,struct Record *src)
{
    ((struct Obj00312 *)p)->f12C=0;
    if(**(u32 * *)&((struct Obj00312 *)p)->f1464==0)func_02034714((const char *)((int)d_021E2EF8),0,(const char *)((int)d_021E2EF8));
    switch(mode) {
    case 0:
        ((struct Obj24359 *)(*(u8 * *)&((struct Obj00312 *)p)->f190))->f0=WIFIBATTLEMATCH_NET_LookupFieldEntry(36);
        ((struct Obj24360 *)(*(u8 * *)&((struct Obj00312 *)p)->f190))->f4=2;
        ((struct Obj24361 *)(*(u8 * *)&((struct Obj00312 *)p)->f190))->f8=1500;
        ((struct Obj24362 *)(*(u8 * *)&((struct Obj00312 *)p)->f190))->f10=WIFIBATTLEMATCH_NET_LookupFieldEntry(39);
        ((struct Obj24363 *)(*(u8 * *)&((struct Obj00312 *)p)->f190))->f14=2;
        ((struct Obj24364 *)(*(u8 * *)&((struct Obj00312 *)p)->f190))->f18=0;
        ((struct Obj24365 *)(*(u8 * *)&((struct Obj00312 *)p)->f190))->f20=WIFIBATTLEMATCH_NET_LookupFieldEntry(40);
        ((struct Obj24366 *)(*(u8 * *)&((struct Obj00312 *)p)->f190))->f24=2;
        ((struct Obj24367 *)(*(u8 * *)&((struct Obj00312 *)p)->f190))->f28=0;
        ((struct Obj24368 *)(*(u8 * *)&((struct Obj00312 *)p)->f190))->f30=WIFIBATTLEMATCH_NET_LookupFieldEntry(38);
        ((struct Obj24369 *)(*(u8 * *)&((struct Obj00312 *)p)->f190))->f34=2;
        ((struct Obj24370 *)(*(u8 * *)&((struct Obj00312 *)p)->f190))->f38=0;
        ((struct Obj24371 *)(*(u8 * *)&((struct Obj00312 *)p)->f190))->f40=WIFIBATTLEMATCH_NET_LookupFieldEntry(37);
        ((struct Obj24372 *)(*(u8 * *)&((struct Obj00312 *)p)->f190))->f44=2;
        ((struct Obj24373 *)(*(u8 * *)&((struct Obj00312 *)p)->f190))->f48=0;
        ((struct Obj24374 *)(*(u8 * *)&((struct Obj00312 *)p)->f190))->f50=(u32)d_021E2F8C;
        ((struct Obj24375 *)(*(u8 * *)&((struct Obj00312 *)p)->f190))->f54=8;
        ((struct Obj24376 *)(*(u8 * *)&((struct Obj00312 *)p)->f190))->f58=(u32)src;
        ((struct Obj24377 *)(*(u8 * *)&((struct Obj00312 *)p)->f190))->f5C=1332;
        ((struct Obj00312 *)p)->f198=6;
        break;
    case 1:
        WIFIBATTLEMATCH_NET_GetDateTime(p+0x38);
        ((struct Obj00312 *)p)->f198=1;
        ((struct Obj24378 *)(*(u8 * *)&((struct Obj00312 *)p)->f190))->f0=(u32)d_021E2F38;
        ((struct Obj24379 *)(*(u8 * *)&((struct Obj00312 *)p)->f190))->f4=8;
        ((struct Obj24380 *)(*(u8 * *)&((struct Obj00312 *)p)->f190))->f8=(u32)(p+0x38);
        ((struct Obj24381 *)(*(u8 * *)&((struct Obj00312 *)p)->f190))->fC=6;
        break;
    case 2:WIFIBATTLEMATCH_NET_SetupGdbRecord((char *)p);break;
    case 3:
        *(struct Record *)(p+0x1c4)=*src;
        ((struct Obj00312 *)p)->f198=2;
        ((struct Obj24382 *)(*(u8 * *)&((struct Obj00312 *)p)->f190))->f0=d_021E2DF8[((struct Obj00312 *)p)->f214];
        ((struct Obj24383 *)(*(u8 * *)&((struct Obj00312 *)p)->f190))->f4=8;
        ((struct Obj24384 *)(*(u8 * *)&((struct Obj00312 *)p)->f190))->f8=(u32)(p+0x1c4);
        ((struct Obj24385 *)(*(u8 * *)&((struct Obj00312 *)p)->f190))->fC=80;
        ((struct Obj24386 *)(*(u8 * *)&((struct Obj00312 *)p)->f190))->f10=(u32)d_021E2F7C;
        ((struct Obj24387 *)(*(u8 * *)&((struct Obj00312 *)p)->f190))->f14=0;
        ((struct Obj24388 *)(*(u8 * *)&((struct Obj00312 *)p)->f190))->f18=(((struct Obj00312 *)p)->f214+1)%6;
        break;
    }
}
