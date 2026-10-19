/*
 * unit: yes
 * function: BR_CODEIN_ProfileCreateActors4, BR_CODEIN_ProfileReturnTrue
 * address: 0x021E138C
 * packet: pkt_ov183_021E138C
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Follower: 021E13D4 return-one stub, after 021E13D2 alignment.
 * symbols:
 *   BR_CODEIN_ProfileSetupSprite 0x021E0840 thumb ov183
 *   BR_CODEIN_ProfileUpdateActorVisible 0x021E0E4C thumb ov183
 *   BR_CODEIN_ProfileCreateRecordActors 0x021E0954 thumb ov183
 *   BR_CODEIN_ProfileSetActorAnimFrame 0x021E0E90 thumb ov183
 *   BR_CODEIN_ProfileCreateMarkerActors 0x021E0A88 thumb ov183
 *   BR_CODEIN_ProfileCreateArrowActors 0x021E0C04 thumb ov183
 *   BR_CODEIN_ProfileUpdateActorPos 0x021E1008 thumb ov183
 *   BR_CODEIN_ProfileCreateOam 0x021E10A0 thumb ov183
 *   BR_CODEIN_ProfileCreateOamObjects 0x021E10F4 thumb ov183
 *   BR_CODEIN_ProfileSetAnimSeq 0x021E1374 thumb ov183
 */
extern void BR_CODEIN_ProfileSetupSprite(char *);
extern void BR_CODEIN_ProfileUpdateActorVisible(char *);
extern void BR_CODEIN_ProfileCreateRecordActors(char *);
extern void BR_CODEIN_ProfileSetActorAnimFrame(char *,int);
extern void BR_CODEIN_ProfileCreateMarkerActors(char *);
extern void BR_CODEIN_ProfileCreateArrowActors(char *);
extern void BR_CODEIN_ProfileUpdateActorPos(char *);
extern void BR_CODEIN_ProfileCreateOam(char *);
extern void BR_CODEIN_ProfileCreateOamObjects(char *);
extern void BR_CODEIN_ProfileSetAnimSeq(char *,int);
int BR_CODEIN_ProfileCreateActors4(char *p)
{
    BR_CODEIN_ProfileSetupSprite(p);
    BR_CODEIN_ProfileUpdateActorVisible(p);
    BR_CODEIN_ProfileCreateRecordActors(p);
    BR_CODEIN_ProfileSetActorAnimFrame(p,0);
    BR_CODEIN_ProfileCreateMarkerActors(p);
    BR_CODEIN_ProfileCreateArrowActors(p);
    BR_CODEIN_ProfileUpdateActorPos(p);
    BR_CODEIN_ProfileCreateOam(p);
    BR_CODEIN_ProfileCreateOamObjects(p);
    BR_CODEIN_ProfileSetAnimSeq(p,1);
    return 0;
}
int BR_CODEIN_ProfileReturnTrue(void)
{
    return 1;
}
