/*
 * unit: yes
 * function: func_021B9F58, func_021B9F68, func_021B9F6C
 * address: 0x021B9F58
 * packet: pkt_ov069_021B9F58
 * region: ov069
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * evidence: 02025D14 forwards r0 to 02030164, whose body reads the pointer
 * and returns a predicate; its legacy void(void) declaration is incomplete.
 * symbols:
 *   func_02025D14 0x02025D14 thumb
 */
extern int func_02025D14(void *p);
int func_021B9F58(char *p)
{
    return func_02025D14(*(void **)(p + 0x14C));
}
void func_021B9F68(void) {}
void func_021B9F6C(void) {}
