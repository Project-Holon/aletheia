/*
 * function: func_021F0EFC
 * address: 0x021F0EFC
 * packet: pkt_ov107_021F0EFC
 * region: ov107
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * evidence: 112-byte request copy, heap halfword at54, and own matched
 * 0203CBAC/0203E5F8 bodies establish all three/two arguments. The third
 * CBAC input carries the unchanged pointer word through its u32 parameter.
 * Halfword flag fields reproduce every original read/store without volatile.
 * symbols:
 *   request_021F6C94 0x021F6C94 data a4
 *   GFL_NET_StartSession 0x0203CBAC arm
 *   GFL_NET_LOWER_DATA_Init 0x0203E5F8 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {
    u32 f00,f04; u8 pad08[0x40]; u32 f48; u8 pad4c[8];
    u16 f54,f56,f58,f5a,f5c,f5e;
    u8 pad60,f61,pad62[3],f65,pad66,f67,pad68[8];
} Request;
typedef struct {
    u16 b00:1,b01:1,b02:1,b03:1,b04:1,b05:1,b06:1,b07:1;
    u16 b08:1,b09:1,b10:1,b11:1,b12:1,b13:1,b14:1,b15:1;
} Flags;
typedef struct {
    u16 heap; u8 pad02[22]; Flags f18,f1a;
    u8 f1c,pad1d; u16 f1e; u8 f20,pad21[3]; u32 f24;
} State;
extern const Request request_021F6C94;
struct Req;
extern void GFL_NET_StartSession(struct Req *req, u32 a2, u32 a3);
extern void GFL_NET_LOWER_DATA_Init(int,int);
void func_021F0EFC(State *p)
{
    Request q=request_021F6C94;
    q.f54=p->heap;
    GFL_NET_StartSession((struct Req *)(&q),0,(u32)p);
    p->f24=0;
    p->f18.b00=0;
    p->f1e=0;
    p->f18.b03=0;
    p->f1c=0;
    p->f18.b04=0;
    p->f18.b05=0;
    p->f18.b06=0;
    p->f18.b07=0;
    p->f18.b08=0;
    p->f18.b09=0;
    p->f18.b10=0;
    p->f18.b11=1;
    p->f18.b14=0;
    p->f18.b13=0;
    p->f18.b15=0;
    p->f1a.b00=0;
    p->f1a.b01=0;
    p->f1a.b02=0;
    p->f1a.b03=0;
    p->f1a.b04=0;
    p->f1a.b05=0;
    p->f20=0;
    GFL_NET_LOWER_DATA_Init(p->heap,0);
}
