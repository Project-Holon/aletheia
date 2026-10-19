/*
 * function: PDWACC_MESSAGE_FormatNumber
 * address: 0x021D97CC
 * packet: pkt_ov123_021D97CC
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: copy the 64-byte halfword table as an aggregate; checksum occupies the high word,
 * with its call result held until after arg initialization. Bind the narrowed digit index
 * before shifting v, then load the indexed halfword in the call argument.
 * symbols:
 *   GF_STANDARD_CalcCrc16 0x0203F1FC arm
 *   STRBUF_Clear 0x0204581C arm
 *   STRBUF_AppendChar 0x02045AFC arm
 *   d_021DA868 0x021DA868 data a2
 *   d_021DA864 0x021DA864 data a2
 *   GF_FONT_AppendTag  0x0201D60C  thumb  arm9
 */
typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef struct { u16 a[32]; } Table;
extern const Table d_021DA868;
extern const u16 d_021DA864;
extern u16 GF_STANDARD_CalcCrc16(const u8 *src, u32 len);
struct U16Vec;
extern void STRBUF_Clear(struct U16Vec *vec);
extern void STRBUF_AppendChar(struct U16Vec *vec, u16 value);
extern void GF_FONT_AppendTag(void *s, u32 b, u32 c, u16 n, const u16 *arr);
void PDWACC_MESSAGE_FormatNumber(int value, void *p)
{
    Table table;
    int copy;
    u32 checksum;
    u16 arg;
    u64 v;
    int i;
    table=d_021DA868;
    copy=value;
    checksum=GF_STANDARD_CalcCrc16((const u8 *)(&copy),4);
    arg=d_021DA864;
    v=(u64)(long long)copy+((u64)checksum<<32);
    STRBUF_Clear(p);
    for (i=0;i<10;i++) {
        u16 index;
        index=(u16)(v&31);
        v>>=5;
        STRBUF_AppendChar(p,table.a[index]);
        GF_FONT_AppendTag(p,189,4,1,&arg);
    }
}
