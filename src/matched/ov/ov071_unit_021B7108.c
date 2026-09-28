/*
 * unit:     yes
 * function: func_021B7108, func_021B7114
 * address:  0x021B7108
 * packet:   pkt_ov071_021B7108
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Byte initialiser and its getter.
 */

void func_021B7108(void *p)
{
    *(unsigned char *)((char *)p + 4) = 1;
    *(unsigned char *)((char *)p + 5) = 0;
    *(unsigned char *)((char *)p + 6) = 1;
}

int func_021B7114(void *p)
{
    return *(unsigned char *)((char *)p + 4);
}
