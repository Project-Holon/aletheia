/*
 * function: func_021B658C
 * address: 0x021B658C
 * packet: pkt_ov101_021B658C
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: pack the words with unsigned left/right shift pairs; u8 casts
 *   keep separate truncation shifts and add eight bytes.
 * symbols:
 *   func_02087C88 0x02087C88 arm
 *   func_020120F4 0x020120F4 thumb
 *   func_02012944 0x02012944 thumb
 *   func_02008494 0x02008494 thumb
 *   func_02012934 0x02012934 thumb
 *   func_0201AB28 0x0201AB28 thumb
 *   func_02017E1C 0x02017E1C thumb
 *   func_0203F4E4 0x0203F4E4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Data { u32 f00; u8 f04,f05; u16 f06; u8 f08,f09,f0a; unsigned char low:4; unsigned char high:4; u8 tail[32]; } Data;
typedef struct Config { u8 bytes[0x54]; } Config;
typedef struct Four { int a,b,c,d; } Four;
extern void func_02087C88(Config *);
struct BigObj;
struct Ctx;
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012944(void *p);
extern void func_02008494(void *,void *);
extern void *func_02012934(const struct BigObj *p);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern void func_0203F4E4(Four *);
void func_021B658C(void *p,Data *out)
{
    Config config;
    Four four;
    void *sub;
    void *record;
    int flag;
    func_02087C88(&config);
    sub=func_020120F4(p);
    p=func_02012944(sub);
    out->f04=config.bytes[2];
    out->f05=config.bytes[3];
    func_02008494(p,out->tail);
    record=func_0201AB28(func_02012934(sub),0);
    flag=0;
    out->f06=func_02017E1C(record,5,0);
    out->f08=func_02017E1C(record,111,0);
    out->f09=func_02017E1C(record,110,0);
    out->f0a=func_02017E1C(record,76,0);
    func_0203F4E4(&four);
    if(four.c == 14) flag=1;
    out->low=(u8)flag;
    out->f00=((u32)four.a << 24) | (((u32)four.b << 24) >> 8) | (((u32)four.c << 24) >> 16) | four.d;
}
