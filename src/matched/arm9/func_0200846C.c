/*
 * function: MYSTATUS_Create
 * address:  0x0200846C
 * packet:   pkt_0200846C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   mystatus_file_name      0x020A70AC  data
 *   RECORD_CeilingRowTable      0x020A70C4  data
 *   RECORD_CeilingTable      0x0209DDB4  data
 *   MAIL_FileName      0x020A716C  data
 *   MYSTATUS_Init  0x020084A0  thumb
 */

extern char mystatus_file_name[];
typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
struct Sub0200852CObj;
extern void MYSTATUS_Init(struct Sub0200852CObj *obj);
void *MYSTATUS_Create(int a0)
{
    void *p = func_02030734((unsigned short)a0, 0x20, 0, mystatus_file_name, 0x34);
    MYSTATUS_Init(p);
    return p;
}
