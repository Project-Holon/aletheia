/*
 * function: func_021FCEA8
 * address: 0x021FCEA8
 * packet: pkt_ov132_021FCEA8
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203996C 0x0203996C arm
 *   func_0203D3F8 0x0203D3F8 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Entry;
struct Request {u8 kind;u32 value;};
extern struct Entry *func_0203996C(int);
extern u32 func_0203D3F8(u32,u32,u32,u32,u32,u32,u32,u32);
void func_021FCEA8(int unused,int kind,u32 value,u32 id) {struct Entry *e;struct Request request;e=func_0203996C(255);request.kind=kind;request.value=value;func_0203D3F8((u32)e,id,0x1100,8,(u32)&request,1,0,0);}
