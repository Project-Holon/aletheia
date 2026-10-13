/*
 * function: INTRUDE_COMM_GetWorkIfRunning
 * address:  0x02158344
 * packet:   pkt_02158344
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GAME_COMM_GetWork  0x02026474  thumb
 *   func_0200FB24  0x0200FB24  thumb
 *   GAME_COMM_GetKind  0x02026454  thumb
 *   GAME_COMM_IsTransition  0x02026460  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 GAME_COMM_GetWork(void *obj);
extern u32 func_0200FB24(void);
extern u32 GAME_COMM_GetKind(void *obj);
extern u32 GAME_COMM_IsTransition(void *obj);

int INTRUDE_COMM_GetWorkIfRunning(int a0)
{
    int t4;
    int t5;

t5 = a0 + 0;
    a0 = GAME_COMM_GetWork((void *)a0);
loc_0215834C:
t4 = a0 + 0;
    a0 = func_0200FB24();
loc_02158352:
    if (a0 != 0) goto loc_0215836E;
loc_02158356:
a0 = t5 + 0;
    a0 = GAME_COMM_GetKind((void *)a0);
loc_0215835C:
    if (a0 != 2) goto loc_0215836E;
loc_02158360:
a0 = t5 + 0;
    a0 = GAME_COMM_IsTransition((void *)a0);
loc_02158366:
    if (a0 == 1) goto loc_0215836E;
loc_0215836A:
    if (t4 != 0) goto loc_02158372;
loc_0215836E:
a0 = 0;
    return a0;
loc_02158372:
a0 = t4 + 0;
    return a0;}
