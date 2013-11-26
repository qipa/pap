/**
 * PAP Engine ( https://github.com/viticm/pap )
 * $Id config.h
 * @link https://github.com/viticm/pap for the canonical source repository
 * @copyright Copyright (c) 2013-2013 viticm( viticm@126.com )
 * @license
 * @user viticm<viticm@126.com>
 * @date 2013-11-26 9:41:11
 * @uses 服务器配置文件操作类 因为与config.h基本定义冲突，所以基本定义在这里更换为define.h
 */
#ifndef PAP_SERVER_COMMON_BASE_CONFIG_H_
#define PAP_SERVER_COMMON_BASE_CONFIG_H_

#include "server/common/base/define.h"
#include "common/game/define.h"

namespace pap_server_common_base {
  
  //武侠世界设计的并不好，我相信天龙已经改正了这些问题(我这里将各个设置分开，并非直接塞在一个结构体内)
  typedef struct {
    float drop_param; //全局掉落修正参数
    uint32_t equipment_damage_point; //全局耐久修正
    uint8_t respawn_param; //全局怪物刷新时间修正，0表示马上刷新，1.0表示按照配置刷新
    uint16_t pk_refix_of_damage; //PK时伤害减半
    uint8_t prentice_proffer_exp; //徒弟贡献给师傅的经验比率
    uint8_t god_relive_top_level; //能原地复活的最大级别
    uint8_t audit_switch; //统计和审计用日志的开关
    uint8_t auto_remove_bad_pet; //是否自动移除错误宠物的开关
  } global_setting_t;

  typedef struct {
    uint8_t language; //0:en,1:cn,2:tw,3:ko,4:vi; 语言支持，这个需要考虑字典问题
  } localization_setting_t; //config localization setting

  typedef struct {
    uint8_t size; //一个Zone的尺寸，正方形
  } zone_setting_t; //config zone setting

  typedef struct {
    uint32_t recover_time; //回血时间
    uint32_t disconnect_time1; //角色断线后，继续在游戏里停留的时间
    uint32_t disconnect_time2; //角色隐藏后，继续在游戏里停留的时间
    uint32_t kick_user_time; //角色没有响应的时间，时间到后踢除
    uint32_t smu_kick_user_time; //角色踢人持续的时间，即持续踢多长时间
    uint32_t drop_box_recycle; //掉落包回收时间
    uint32_t time_change_interval; //时辰变更间隔
    uint32_t packet_audit_time; //统计网络包的发送数量、频率的时间间隔。为0时为不统计
  } time_setting_t;
  
  typedef struct {
    uint32_t max_count; //游戏世界的怪物数量上限
    uint32_t default_respawn_time; //缺省的怪物重生时间
    uint32_t default_position_range; //缺省的怪物重生范围
    uint8_t default_ai_type; //缺省的怪物AI类型
    uint32_t default_body_time; //普通怪尸体保留时间（毫秒）
    uint16_t odds_of_change_target; //切换攻击目标的几率
    uint16_t odds_of_attack_assistant; //攻击协助者的几率
    uint16_t change_target_cooldown; //切换目标的冷却时间, 单位秒
    uint8_t default_max_level; //怪的最大等级
  } monster_setting_t;

  typedef struct {
    uint32_t max_count; //游戏世界传送点数量上限
  } portal_setting_t;

  typedef struct {
    uint16_t max_count; //游戏世界提供的生活技能辅助操作台数量上限（炼丹炉等等）
  } platform_setting_t;

  typedef struct {
    uint16_t max_count; //游戏世界的SkillObj数量上限
  } skill_obj_setting_t;

  typedef struct {
    uint16_t max_count; //游戏世界的SpecialObj数量上限
  } special_obj_setting_t;

  typedef struct {
    uint16_t max_count; //游戏世界的BusObj数量上限
  } bus_obj_setting_t;

  typedef struct {
    uint16_t max_count; //游戏世界的玩家商店的数量上限
    uint32_t payment_per_hour; //每小时附加扣除的钱数
  } player_shop_setting_t;

  typedef struct {
    uint16_t max_count; //场景定时器的最大数量
  } scene_timer_setting_t;

  typedef struct {
    uint16_t max_count; //角色定时器的最大数量
  } human_timer_setting_t;
  
  typedef struct {
    uint32_t max_count; //宠物最大数量
    uint32_t body_time; //宠物尸体存在时间
    uint32_t happiness_interval; //宠物快乐度下降1的时间间隔(毫少)
    uint32_t life_interval; //宠物寿命下降1次的时间间隔(毫少)
    uint8_t dec_life_step; //珍兽寿命下降1次的值
    uint8_t call_up_happiness; //物快乐度大于才可以召出,现在快乐度上限为100
    uint32_t placard_time; //发布宠物公告的持续时间（毫秒）
    uint32_t placard_need_level; //发布宠物公告所需宠物等级
    uint32_t placard_need_happiness; //发布宠物公告所需宠物快乐度
    uint32_t placard_need_life; //发布宠物公告所需宠物寿命
    uint8_t compound_gen_gu_float; //宠物合成时根骨变动%比
    uint8_t compound_grow_float; //宠物合成时成长率变动%比
    uint8_t compound_baby_per_wild_with_wild; //野生宠与野生宠合成时生成宝宝宠的几率%比，否则生成野生宠
    uint8_t compound_baby_per_baby_with_baby; //宝宝宠与宝宝宠合成时生成宝宝宠的几率%比，否则生成野生宠
    uint8_t compound_baby_per_wild_with_baby; //野生宠与宝宝宠合成时生成宝宝宠的几率%比，否则生成野生宠
    uint8_t compound_perception_per; //宠物合成时资质取自母宠的几率%比，否则取自父宠
    uint8_t default_max_level; //宠物可以通过经验升到的最高等级
    float die_lreduce_life; //宠物被怪打死时减少其寿命，只有在被怪物(宠物不算怪)打死后才掉寿命
  } pet_setting_t;

  typedef struct {
    uint8_t can_get_exp_range; //杀死角色后可以得到EXP的范围
    uint32_t out_ghost_time; //玩家释放灵魂的时间
    uint32_t default_move_speed; //缺省角色移动速度
    uint32_t default_attack_speed; //缺省角色攻击速度，没有武器时候的攻击速度
    uint32_t default_refresh_rate; //角色自动增长数据的刷新速度
    uint32_t energy_vigor_recover_interval; //精力与活力的恢复时间间隔（毫秒）
    uint8_t default_max_level; //玩家可以通过经验升到的最高等级
    uint32_t pk_value_refresh_rate; //杀气值衰减时间间隔（秒）
    uint32_t default_pilfer_lock_time; //缺省安全锁时间(毫秒)
    uint8_t default_xinfa_max_level; //心法最大等级
    uint8_t level_up_validate_min_level; //升级图形验证的最小等级(包含该等级)
    uint8_t level_up_validate_max_level; //升级图形验证的最大等级（包含该等级）
    uint8_t can_get_yuanbao_ticket_min_level; //获得元宝票的最小等级
  } human_setting_t;

  typedef struct {
    uint16_t available_follow_dist; //组队跟随的有效距离(米)
    uint32_t time_for_lose_follow; //组队跟随超出有效距离多长时间后主动退出组队跟随(秒)
  } team_setting_t;

  typedef struct {
    uint16_t found_duration; //帮会创建过程所允许的最大时间（小时为单位），超过时间没有满足条件则帮会创建失败
    uint16_t default_max_member_count; //帮会新建时默认最大帮众上限
    uint8_t response_user_count; //帮会从建立到成立需要响应的玩家数量（含帮会建立者）
    uint16_t xianya_max_user[5]; //一到五级县衙人口上限
    uint32_t xianya_standard_money[5]; //一到五级县衙标准资金
    uint32_t xianya_max_money[5]; //一到五级县衙资金上限
    uint8_t xianya_max_trader[5]; //一到五级县衙商人数量上限
    uint32_t bank_standard_money[5]; //一到五级钱庄标准资金
    uint16_t wing_max_user[5]; //一到五级厢房人口上限
    uint32_t create_city_money; //创建城市需要的金钱
    uint32_t leave_word_cost; //帮会留言消耗的金钱
    uint32_t battle_time; //宣战时间
    uint8_t left_guild_buff_enable; //是否增加离帮BUFF
    uint16_t boom_max_value; //帮派繁荣度最大值
    float boom_scale_all; //繁荣度计算参数
    float boom_scale_online_count; //繁荣度计算参数 上线成员总数权重
    float boom_scale_attribute_increase; //繁荣度计算参数 六项属性增长权重
    float boom_scale_trader_transactions_count; //繁荣度计算参数 跑商次数权重
    float boom_scale_avg_boom; //繁荣度计算参数 前六天繁荣度平均权重
    float boom_scale_dilation; //繁荣度计算扩张权重参数
    float boom_scale_farming; //繁荣度计算农业权重参数
    float boom_scale_trading_mission; //繁荣度计算商业权重参数
    float boom_scale_defence; //繁荣度计算防御权重参数
    float boom_scale_industry; //繁荣度计算工业权重参数
    float boom_scale_technology; //繁荣度计算技术权重参数
    uint16_t trade_ticket_decrease_value; //商票衰减值（新建帮派繁荣初始值）
    bool trading_mission_plug; //帮派跑商任务防外挂开关
    bool validate_xianya_level; //是否在加载时修正等级不同的县衙 
  } guild_setting_t;

  typedef struct {
    uint16_t max_count; //每个WORLD上可申请的最大公会同盟数
    uint16_t quit_league_wait_time; //退盟后再次申请加盟的时间间隔（小时）
    uint32_t create_money; //创建同盟需要的金钱
  } guild_league_setting_t;

  typedef struct {
    uint16_t password_point; //多少点友好度需要输入二级密码
    uint16_t prompt_point; //多少点友好度需要提示上下线
    uint32_t get_point_need_exp; //获得多少经验可以提升友好度
  } relation_setting_t;

  typedef struct {
    uint16_t delete_delay_time; //多少小时以后再次点击强制解除按钮则删除密码
    uint16_t energy_set_cost; //设置密码消耗的精力
    uint16_t energy_modify_cost; //修改密码消耗的精力
    uint16_t energy_unlock_cost; //强行解除密码消耗的精力
    uint16_t input_error_times_per_day; //每天输入的最大错误次数
    uint16_t password_unlock_time; //二级密码解锁生效时间（单位：小时）
  } minor_password_setting_t;

  typedef struct {
    uint32_t hash_online_user_count; //在线玩家的hash表大小
    uint32_t hash_mail_user_count; //拥有邮件的玩家hash表大小
    uint32_t max_offline_user_count; //用于保存登陆过游戏的玩家最大数量
    uint8_t speaker_pool_max; //小喇叭消息池大小（测试使用，大小值不得超越128）
  } world_setting_t;

  typedef struct {
    char user_path[FILENAME_MAX];
  } temp_setting_t;

  typedef struct {
    uint32_t default_damage_fluctuation; //缺省的攻击浮动值
    uint16_t h0_of_hit_calculation; //命中计算中的参数H0
    uint16_t c0_of_critical_calculation; //会心计算中的参数C0
    uint16_t c1_of_critical_calculation; //会心计算中的参数C1
    uint16_t c2_of_critical_calculation; //会心计算中的参数C2
  } combat_setting_t;

  typedef struct {
    uint32_t min_value; //最小善恶值
    uint32_t max_value; //最大善恶值
    uint8_t get_value_need_level; //获得善恶值的最低等级
    uint8_t give_value_min_level; //能给队长带来善恶值的队友最低等级
    uint8_t give_value_max_level; //能给队长带来善恶值的队友最高等级
    uint8_t give_value_difference_level; //能给队长带来善恶值的队友最低等级差
    uint16_t give_value_radius; //获得善恶值的半径
    uint32_t per_member_give_value; //每个有效队友能增加的善恶值点数
    uint32_t per_disciple_give_value; //每个有效徒弟能增加的善恶值额外点数
    uint32_t once_max_give_value; //杀死一只怪能给队长带来的最大善恶值点数
    uint32_t member_die_cost_value; //有效队友的死亡减少队长的善恶值点数
  } good_and_evil_setting_t;

  typedef struct {
    uint16_t min; //最小剧情点数
    uint16_t max; //最大剧情点数
  } plot_point_setting_t;

  typedef struct {
    float rate_a; //玩家向商店出售已经鉴定过的物品或者无需鉴定的物品按照基础价格*系数A(=1/3)
    float rate_b; //若出售未鉴定物品，价格应该更低，设此价格系数为B(=1/10)
    uint16_t yuanbao_transaction_scene_id; //元宝交易场景ID
    uint32_t yuanbao_ticket_max; //官票所含最大元宝数
    float new_server_sale_rate; //新服活动价格参数
    uint8_t min_exchange_code_level; //交易需要加验证码的级别需求底限（包含该等级）
    uint8_t max_exchange_code_level; //交易需要加验证码的级别需求上限（包含该等级）
  } economic_setting_t;

  typedef struct {
    float revise_param; //修正参数
    float team_spouse_add_rate; //队伍配偶加成比例
    float team_brother_add_rate; //队伍兄弟加成比例
    float team_master_in_add_rate; //有师傅并在队中的经验加成
    float team_master_notin_add_rate; //有师傅但不在队中的经验加成
    float team_disciple_add_rate; //收徒后的经验加成
    float hidden_or_magic_weapon_absorb_rate; //暗器（法宝）吸收经验率
  } exp_setting_t;

  typedef struct {
    uint32_t continue_time; //决斗持续时间
    uint8_t need_min_level; //决斗的最小等级限制需求
    uint16_t need_energy; //决斗需要的精力
  } duel_setting_t;

  typedef struct {
    uint32_t continue_time; //宣战持续时间
  } warfare_setting_t;

  typedef struct {
    uint32_t flag_switch_delay; //PK开关的关闭延迟时间
    uint32_t hostile_player_warning; //PK中敌意玩家的警告时间
  } pk_setting_t;

  typedef struct {
    uint32_t legal_fight_back_time; //合法反击的持续时间
  } fight_back_setting_t;

  typedef struct {
    float assistant_demand_formula_param[4]; //辅助技能的消耗减少公式的参数1-4
  } ability_setting_t;

  typedef struct {
    uint8_t enable_state; //是否打开疲劳状态
    uint32_t little_fatigue_time; //轻微疲劳的总在线时间定义(s)
    uint32_t exceeding_fatigue_time; //极度疲劳的总在线时间定义(s)
    uint32_t reset_fatigue_state_offline_time; //消除疲劳的总离线时间定义(s)
  } fatigue_setting_t;

  typedef struct {
    uint32_t max_day_can_cost; //最大每日消费的元宝数量(不可超过16777215,0xFFFFFF)
    bool enable_exchage_yuanbao_ticket; //是否开启兑换元宝票
  } yuanbao_setting_t;

  typedef struct {
    uint32_t little_count; //折扣收入的怪物数量,每天杀怪超过这个数量则以比例给收入
    uint32_t nil_count; //完全没有收入的怪物数量
    float little_percent; //折扣收入的百分比
  } monster_income_setting_t;

  typedef struct {
    uint8_t max_count; //允许的上限，该上限只初始化，不会从配置中读取
    uint32_t send_back_time; //多少分钟以后卖不出去则退回玩家
    uint8_t yuanbao_fee; //寄售元宝的费用百分比
    uint8_t gold_coin_fee; //寄售金币的费用百分比
    uint32_t yuanbao_value[3]; //元宝数量的三个选项
    uint32_t gold_coin_value[3]; //金币数量的三个选项
    bool is_close_yuanbao_sell; //是否关闭元宝寄售
    bool is_close_gold_coin_sell; //是否关闭金币寄售
  } commision_shop_setting_t;

  typedef struct {
    uint16_t login_cache_time; //计玩家第一次登陆日志的间隔时间,以小时为单位
  } cache_log_time_setting_t; 

  typedef struct {
    bool join_guild; //加入帮派是否通知
  } system_notice_setting_t;

  typedef struct {
    uint8_t hour_point[3]; //统计的三个时间点（小时）
  } player_count_of_scene_setting_t; //统计服务器中场景的人数

  typedef struct {
    bool state[10]; //留十个标志位，具体卡牌的定义以配置中为准
  } active_riches_card_setting_t;

  struct config_info {
    global_setting_t global; 
    localization_setting_t localization;
    zone_setting_t zone;
    time_setting_t time;
    monster_setting_t monster;
    portal_setting_t portal;
    platform_setting_t platform;
    special_obj_setting_t special_obj;
    skill_obj_setting_t skill_obj;
    bus_obj_setting_t bus_obj;
    player_shop_setting_t player_shop;
    scene_timer_setting_t scene_timer;
    human_timer_setting_t human_timer;
    pet_setting_t pet;
    human_setting_t human;
    team_setting_t team;
    guild_setting_t guild;
    guild_league_setting_t guild_league;
    relation_setting_t relation;
    minor_password_setting_t minor_password;
    world_setting_t world;
    temp_setting_t temp;
    combat_setting_t combat;
    good_and_evil_setting_t good_and_evil;
    plot_point_setting_t plot_point;
    economic_setting_t economic;
    exp_setting_t exp;
    duel_setting_t duel;
    warfare_setting_t warfare; 
    pk_setting_t pk;
    fight_back_setting_t fight_back;
    ability_setting_t ability;
    fatigue_setting_t fatigue;
    yuanbao_setting_t yuanbao;
    monster_income_setting_t monster_income;
    commision_shop_setting_t commision_shop;
    cache_log_time_setting_t cache_log_time;
    system_notice_setting_t system_notice;
    player_count_of_scene_setting_t player_count_of_scene;
    active_riches_card_setting_t active_riches_card;
    config_info(); //init function
    ~config_info(); //destruct function
  }; //params define please see the run/server/config_info.ini 
  
  //login info
  struct login_info {
    uint16_t login_id;
    char db_ip[IP_SIZE]; //database ip address 
    uint16_t db_port; //database port
    char db_connection_name[DB_CONNECTION_NAME_LENGTH]; //odbc connection name
    char db_user[DB_USER_NAME_LENGTH]; //database use user name
    char db_password[DB_PASSWORD_LENGTH]; //database password
    bool encrypt_password; //if encrypt password
    uint16_t client_version; 
    uint8_t db_connect_count;
    uint16_t turn_player_count;
    uint8_t proxy_connect; //客户端来自代理服务器,0允许代理连接，1不允许代理连接，2仅允许教育网代理
    bool relogin_limit; //是否开启ReLogin限制功能
    bool relogin_stop; //重登是否停止
    uint32_t relogin_stop_time; //重新登陆停止的时间
    bool notify_safe_sign; //是否进行安全提醒 

  };
}; //namespace pap_server_common_base

#endif //PAP_SERVER_COMMON_BASE_CONFIG_H_
