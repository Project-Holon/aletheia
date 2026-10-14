/*
 * function: GURU2_RECEIPT_StateWaitAnswers
 * address: 0x021DDB04
 * packet: pkt_ov137_021DDB04
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: 021DDB46 store then 021DDB48 re-read of s16 field at 0x4820
 * symbols:
 *   GURU2_RECEIPT_GetUnionApp 0x021DCF50 thumb ov137
 *   UNION_APP_GetMemberCount 0x021841A4 thumb ov022
 *   GURU2_RECEIPT_GetMemberCount 0x021DE354 thumb ov137
 *   GURU2_RECEIPT_Noop 0x021DD924 thumb ov137
 *   MI_CpuFill8 0x02082BCC arm
 *   GFL_NET_SYSTEM_GetCurrentAid 0x02039338 arm
 *   GURU2_COMM_Send 0x021DCBC4 thumb ov137
 */
#include "../include/Obj03303.h"
#include "../include/Obj23720.h"
#include "../include/Obj23721.h"
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned char  u8;
extern void *GURU2_RECEIPT_GetUnionApp(u8 *p);
typedef unsigned int   u32;
extern int UNION_APP_GetMemberCount(unsigned char *p);
extern int GURU2_RECEIPT_GetMemberCount(void *p);
extern void GURU2_RECEIPT_Noop(char *);
extern void MI_CpuFill8(void *, int, unsigned);
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
extern void GURU2_COMM_Send(void *p, u32 a, const void *b, u32 c);
int GURU2_RECEIPT_StateWaitAnswers(char *p, int state) {
    unsigned char buf[4];
    if (((struct Obj23720 *)(*(char * *)&((struct Obj03303 *)p)->f10))->f38 != UNION_APP_GetMemberCount(GURU2_RECEIPT_GetUnionApp((u8 *)p)) ||
        ((struct Obj23721 *)(*(char * *)&((struct Obj03303 *)p)->f10))->f38 != GURU2_RECEIPT_GetMemberCount(p)) {
        ((struct Obj03303 *)p)->f4820 = 0;
        ((struct Obj03303 *)p)->f118 = 8;
        GURU2_RECEIPT_Noop(p);
        return state;
    }
    ++*(volatile s16 *)&((struct Obj03303 *)p)->f4820;
    if (*(volatile s16 *)&((struct Obj03303 *)p)->f4820 > 30) {
        int zero = 0;
        MI_CpuFill8(buf, 0, 4);
        buf[2] = 1;
        buf[0] = GFL_NET_SYSTEM_GetCurrentAid();
        GURU2_COMM_Send(((struct Obj03303 *)p)->f10, 0x2801, buf, 4);
        ((struct Obj03303 *)p)->f4820 = zero;
        ((struct Obj03303 *)p)->f118 = 9;
    }
    GURU2_RECEIPT_Noop(p);
    return state;
}
