/*
 * function: SCRIPT_WORK_GetWorkValue
 * address: 0x0215901C
 * packet: pkt_ov010_0215901C
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two-byte zero alignment padding follows the 18-byte function.
 * Return stays full-width: the fallback id has no halfword truncation.
 * symbols:
 *   SCRIPT_WORK_GetWorkPtr 0x02158FE0 thumb ov010
 */
typedef unsigned short u16;
extern u16 *SCRIPT_WORK_GetWorkPtr(void *, void *, unsigned int);
unsigned int SCRIPT_WORK_GetWorkValue(void *a, void *b, unsigned int id)
{
    u16 *p = SCRIPT_WORK_GetWorkPtr(a, b, id);
    if (p) id = *p;
    return id;
}
