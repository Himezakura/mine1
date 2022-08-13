#include "cheats.hpp"

namespace CTRPluginFramework
{
	/* 記述例
	Process::Write32(0x00000000, 0x00000000); 32bit書き込み
	Process::Write16(0x00000000, 0x0000); 16bit書き込み
	Process::Write8(0x00000000, 0x00); 8bit書き込み
	
	Process::Read32(0x00000000, data); 32bit読み込み
	Process::Read16(0x00000000, data); 16bit読み込み
	Process::Read8(0x00000000, data); 8bit読み込み
	
	ADDFLOAT(0x00000000, 0.1f) moonjumpや座標移動(加算)
	SUBFLOAT(0x00000000, 0.1f) moonjumpや座標移動(減算)
	
	if (Controller::IsKeysDown(A))　{} ボタン実行
	*/


//スピードハック1
void speed1(MenuEntry *entry){
	Keyboard key("走りながらジャンプすると加速します", {"オン", "オフ"});
 int B = key.Open();
  if (B == 0) {
   Process::Write32(0x19870C, 0x3F8C8000);
  } else if (B == 1) {
   Process::Write32(0x19870C, 0x3F800000);
}}


//スピードハック2
void speed2(MenuEntry *entry){
	Keyboard key("走っている間加速", {"オン", "オフ"});
 int B = key.Open();
  if (B == 0) {
   Process::Write32(0x34BF14, 0x40800000);
  } else if (B == 1) {
   Process::Write32(0x34BF14, 0x3F800000);
}}


//貫通
void kantu(MenuEntry *entry){
	Keyboard key("貫通する種類を選択", {"壁貫通", "床貫通", "オフ"});
 int B = key.Open();
  if (B == 0) {
   Process::Write32(0x718C84, 0xE1A01005);
  } else if (B == 1) {
   Process::Write32(0x718C84, 0xE1A01007);
  } else if (B == 2) {
   Process::Write32(0x718C84, 0xE1A01002);
}}


//HP無限(不安定)
void hp_huan(MenuEntry *entry){
u32 B;
 Process::Read32(0xB08B30, B);
 Process::Write32(B + 0x5C4, 0x41A00000);
}


//空腹度(不安定)
void kuuhuku_huan(MenuEntry *entry){
	u32 B;
 Process::Read32(0xB08B30, B);
 Process::Write32(B + 0xC4C, 0x41A00000);
}









}
