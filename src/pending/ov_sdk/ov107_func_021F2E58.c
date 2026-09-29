extern int g_021F6EEC;
extern unsigned char *g_021F6FA0;

void func_021F2E58(unsigned char file_id)
{
    unsigned char *e;

    if (!(g_021F6EEC & (1 << file_id)))
        return;
    e = g_021F6FA0 + file_id * 0x5D4;
    if (e[0x1D52] == 0 || *(unsigned short *)(e + 0x1D4C) == 0)
        return;
    if (*(unsigned short *)(e + 0x1D4A) > *(unsigned short *)(e + 0x1D48))
        *(unsigned short *)(e + 0x1D48) = *(unsigned short *)(e + 0x1D4A);
    else if (*(unsigned short *)(e + 0x1D48) <= *(unsigned short *)(e + 0x1D4A) + 2)
        *(unsigned short *)(e + 0x1D48) = *(unsigned short *)(e + 0x1D48) + 1;
}
