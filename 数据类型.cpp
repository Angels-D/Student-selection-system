const int 文本长度 = 50, 选课上限 = 30;
const int 选课类型_数量 = 4, 选课性质_数量 = 4, 上课时间_数量 = 5, 上课地点_数量 = 2, 学期_数量 = 10;
//char** 选课类型, ** 选课性质, ** 上课时间, ** 上课地点,**学期,**上课星期;//自定义化读取-未完工
const char 选课类型[选课类型_数量][10] = { "正选","重修","选修","补修" };
const char 选课性质[选课性质_数量][15] = { "实践教学课","公共基础必修课","创业课程","其他" };
const char 上课时间[上课时间_数量][10] = { "第一节","第二节","第三节","第四节","晚上" };
const char 上课星期[7][10] = { "星期一","星期二","星期三","星期四","星期五","星期六", "星期天" };
const char 上课地点[上课地点_数量][10] = { "本部","西校区" };
const char 学期[学期_数量][15] = { "2019上半年","2019下半年","2020上半年" ,"2020年下半年","2021年上半年" ,"2021年下半年" ,"2022年上半年" ,"2022年下半年" ,"2023年上半年","2023年下半年" };
FILE* 用户数据, * 课程数据, * 系统日志;
int 用户数量 = 0, 课程数量 = 0, 登录用户ID = 0, 筛选条件[10][10] = { 0 };//0-显示，1-隐藏
struct 课程 {
	int 课程代码;//-1待删除
	int 学分;
	int 选课性质;
	int 选课类型;
	int 学期;
	int 上课时间;
	int 上课星期;
	char 教师代码[文本长度];
	char 课程名字[文本长度];
	int 上课地点;
	int 学生上限;
	int 用户数量;
	int* 用户ID;
}*课_程 = NULL;
struct 用户 {
	char 账号[文本长度];//学号或工号
	char 密码[文本长度];
	char 姓名[文本长度];
	int 权限类型;//1-学校，2-教师，3-学生，-1-待删除
	int 课程数量;
	int* 课程代码;
}*用_户 = NULL;
union 临时数据
{
	char 文本型[1000];
	char 字符型;
	int 整数型;
	double 小数型;
	FILE* 文件型;
};