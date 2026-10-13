/*
 * function: TRCARD_SYS_Main
 * address:  0x0216F174
 * packet:   pkt_ov010_0216F174
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   TRCARD_SYS_StateChooseScreen  0x0216F244  thumb  ov010
 *   TRCARD_SYS_StateStartCardProc  0x0216F288  thumb
 *   TRCARD_SYS_StateWaitCardProc  0x0216F2B4  thumb
 *   TRCARD_SYS_StateStartEditProc  0x0216F2E0  thumb
 *   TRCARD_SYS_StateWaitEditProc  0x0216F31C  thumb
 *   TRCARD_SYS_StateStartBadgeProc  0x0216F378  thumb
 *   TRCARD_SYS_StateWaitBadgeProc  0x0216F3B0  thumb
 */

extern int TRCARD_SYS_StateChooseScreen(char *a, char *b);
extern int TRCARD_SYS_StateStartCardProc(int *p);
extern int TRCARD_SYS_StateWaitCardProc(char *p);
extern int TRCARD_SYS_StateStartEditProc(char *p);
extern int TRCARD_SYS_StateWaitEditProc(char *a);
extern int TRCARD_SYS_StateStartBadgeProc(char *p);
extern int TRCARD_SYS_StateWaitBadgeProc(char *p);

int TRCARD_SYS_Main(int a, int *b, int c, int d)
{
    switch (*b) {
    case 0:
        *b = TRCARD_SYS_StateChooseScreen((char *)d, (char *)c);
        break;
    case 1:
        *b = TRCARD_SYS_StateStartCardProc((int *)d);
        break;
    case 2:
        *b = TRCARD_SYS_StateWaitCardProc((char *)d);
        break;
    case 3:
        *b = TRCARD_SYS_StateStartEditProc((char *)d);
        break;
    case 4:
        *b = TRCARD_SYS_StateWaitEditProc((char *)d);
        break;
    case 5:
        *b = TRCARD_SYS_StateStartBadgeProc((char *)d);
        break;
    case 6:
        *b = TRCARD_SYS_StateWaitBadgeProc((char *)d);
        break;
    case 7:
    default:
        return 1;
    }
    return 0;
}
