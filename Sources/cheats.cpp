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
   Process::Write32(0x019870C, 0x3F8C8000);
  } else if (B == 1) {
   Process::Write32(0x019870C, 0x3F800000);
}}


//スピードハック2
void speed2(MenuEntry *entry){
	Keyboard key("走っている間加速", {"オン", "オフ"});
 int B = key.Open();
  if (B == 0) {
   Process::Write32(0x034BF14, 0x40800000);
  } else if (B == 1) {
   Process::Write32(0x034BF14, 0x3F800000);
}}


//貫通
void kantu(MenuEntry *entry){
	Keyboard key("貫通する種類を選択", {"壁貫通", "床貫通", "オフ"});
 int B = key.Open();
  if (B == 0) {
   Process::Write32(0x0718C84, 0xE1A01005);
  } else if (B == 1) {
   Process::Write32(0x0718C84, 0xE1A01002);
  } else if (B == 2) {
   Process::Write32(0x0718C84, 0xE1A01007);
}}


//HP無限(不安定)
void hp_huan(MenuEntry *entry){
u32 B;
 Process::Read32(0x0B08B30, B);
 Process::Write32(B + 0x00005C4, 0x41A00000);
}


//空腹度(不安定)
void kuuhuku_huan(MenuEntry *entry){
	u32 B;
 Process::Read32(0x0B08B30, B);
 Process::Write32(B + 0x0000C4C, 0x41A00000);
}


//ダメージの倍率
void dameji_bairitu(MenuEntry *entry){
	Keyboard key("プレイヤー、mobへのダメージ倍率変更", {"即死", "食らわない", "オフ"});
 int B = key.Open();
  if (B == 0) {
   Process::Write32(0x01C3E4C, 0xF0000000);
  } else if (B == 1) {
   Process::Write32(0x01C3E4C, 0x00000000);
  } else if (B == 2) {
   Process::Write32(0x01C3E4C, 0x3F800000);
}}


//ブロックワンパン
void block_wanpan(MenuEntry *entry){
	Keyboard key("アイテムを持っていない状態でワンパン可能", {"オン", "オフ"});
 int B = key.Open();
  if (B == 0) {
   Process::Write32(0x06B1CF8, 0x50000000);
  } else if (B == 1) {
   Process::Write32(0x06B1CF8, 0x3F800000);
}}


//ブロックワンパン(アイテム持ち)
void block_wanpan_turuhasi(MenuEntry *entry){
	Keyboard key("何かしらのアイテムを持っている状態でワンパン可能", {"オン", "オフ"});
 int B = key.Open();
  if (B == 0) {
   Process::Write32(0x071B60C, 0x50000000);
  } else if (B == 1) {
   Process::Write32(0x071B60C, 0x3F800000);
}}


//時間逆転
void jikan_gyaku(MenuEntry *entry){
	Keyboard key("朝なら夜に、夜なら朝になります(少し不安定)", {"オン", "オフ"});
 int B = key.Open();
  if (B == 0) {
   Process::Write32(0x0739640, 0xBF800000);
  } else if (B == 1) {
   Process::Write32(0x0739640, 0x3F800000);
}}


//世界透明化
void sekai_toumei(MenuEntry *entry){
	Keyboard key("全ブロック透明化（チェストとかはならない）", {"オン", "オフ"});
 int B = key.Open();
  if (B == 0) {
   Process::Write32(0x074F964, 0x00000000);
  } else if (B == 1) {
   Process::Write32(0x074F964, 0x3F800000);
}}


//時間変更（朝、夜）
void jikan_henkou(MenuEntry *entry){
	Keyboard key("時間変更（少し不安定）", {"朝", "夜", "オフ"});
 int B = key.Open();
  if (B == 0) {
   Process::Write32(0x0739638, 0x3E800000);
  } else if (B == 1) {
   Process::Write32(0x0739638, 0xBE800000);
  } else if (B == 2) {
   Process::Write32(0x0739638, 0x00000000);
}}


//世界透明化
void sekai_toumei(MenuEntry *entry){
	Keyboard key("雨が降っているときに有効", {"オン", "オフ"});
 int B = key.Open();
  if (B == 0) {
   Process::Write32(0x0649690, 0x00000000);
  } else if (B == 1) {
   Process::Write32(0x0649690, 0x3F800000);
}}


//雷降らす（強制）
void kaminari(MenuEntry *entry){
	Keyboard key("雨が降っているときに有効", {"雷降らす（強制）", "雷降らす（強制） オフ", "雷降った時のact固定",　"雷降った時のact固定　オフ"});
 int B = key.Open();
  if (B == 0) {
   Process::Write32(0x064968C, 0xE1A00000);
  } else if (B == 1) {
   Process::Write32(0x064968C, 0x3C23D70A);
  } else if (B == 2) {
   Process::Write32(0x0649680, 0xC2400000);
  } else if (B == 3) {
   Process::Write32(0x0649680, 0x3F800001);
}}


//霧の色変更
void kiri_color(MenuEntry *entry){
	Keyboard key("霧の色を選択", {"赤", "青", "黄色",　"緑", "紫", "白", "黒", "オフ"});
 int B = key.Open();
  if (B == 0) {
   Process::Write32(0x07393C4, 0x00000000);
   Process::Write32(0x07393C8, 0x40000000);
   Process::Write32(0x07393CC, 0x00000000);
  } else if (B == 1) {
   Process::Write32(0x07393C4, 0x40000000);
   Process::Write32(0x07393C8, 0x00000000);
   Process::Write32(0x07393CC, 0x00000000);
  } else if (B == 2) {
   Process::Write32(0x07393C4, 0x00000000);
   Process::Write32(0x07393C8, 0x40000000);
   Process::Write32(0x07393CC, 0x40000000);
  } else if (B == 3) {
   Process::Write32(0x07393C4, 0x00000000);
   Process::Write32(0x07393C8, 0x00000000);
   Process::Write32(0x07393CC, 0x40000000);
　　}　else if (B == 4) {
   Process::Write32(0x07393C4, 0x40000000);
   Process::Write32(0x07393C8, 0x40000000);
   Process::Write32(0x07393CC, 0x00000000);
  } else if (B == 5) {
   Process::Write32(0x07393C4, 0x00000000);
   Process::Write32(0x07393C8, 0x70000000);
   Process::Write32(0x07393CC, 0x00000000);
  } else if (B == 6) {
   Process::Write32(0x07393C4, 0x00000000);
   Process::Write32(0x07393C8, 0x400000000);
   Process::Write32(0x07393CC, 0x00000000);
  } else if (B == 7) {
   Process::Write32(0x07393C4, 0x3F800000);
   Process::Write32(0x07393C8, 0x3F2BABAC);
   Process::Write32(0x07393CC, 0x3F52D2D4);
}}


//アイテムの個数文字真ん中
void item_slot_suuji(MenuEntry *entry){
	Keyboard key("アイテムの個数文字が真ん中に配置される（ゴミコード）", {"オン", "オフ"});
 int B = key.Open();
  if (B == 0) {
   Process::Write32(0x01ED2AC, 0x40000000);
  } else if (B == 1) {
   Process::Write32(0x01ED2AC, 0x3F800000);
}}


//スロットアイテム着色
void item_slot_color(MenuEntry *entry){
	Keyboard key("スロットアイテムのみ黒くなる", {"オン", "オフ"});
 int B = key.Open();
  if (B == 0) {
   Process::Write32(0x01ED0D8, 0x00000000);
  } else if (B == 1) {
   Process::Write32(0x01ED0D8, 0x3F800000);
}}


//スロットアイテム大きさ変更
void item_slot_ookisa(MenuEntry *entry){
	Keyboard key("スロットアイテムのみ大きさ変更", {"大きい", "通常", "小さい"});
 int B = key.Open();
  if (B == 0) {
   Process::Write32(0x01ED0D4, 0x40B00000);
  } else if (B == 1) {
   Process::Write32(0x01ED0D4, 0x40000000);
　　} else if (B == 2) {
   Process::Write32(0x01ED0D4, 0x3F500000);
}}


//プライヤー透明化
void player_toumei(MenuEntry *entry){
	Keyboard key("", {"オン", "オフ"});
 int B = key.Open();
  if (B == 0) {
   Process::Write32(0x019D320, 0x10000000);
   Process::Write32(0x019D324, 0x90000000);
  } else if (B == 1) {
   Process::Write32(0x019D320, 0x3F800000);
   Process::Write32(0x019D324, 0xBF800000);
}}


//プライヤー発光
void player_hakkou(MenuEntry *entry){
	Keyboard key("", {"白", "通常", "黒"});
 int B = key.Open();
  if (B == 0) {
   Process::Write32(0x01D9868, 0x7FFFFFFF);
  } else if (B == 1) {
   Process::Write32(0x01D9868, 0x3F800000);
　　} else if (B == 2) {
   Process::Write32(0x01D9868, 0x00000000);
}}















}
