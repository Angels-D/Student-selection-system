int 载入文件(void) {
	if (导入用户(0) == -1) exit(-1);
	if (导入课程(0) == -1) exit(-1);
	数据校验(0);
	system("pause"); system("cls");
	return 0;
}
int 登陆(void) {
	临时数据 账号, 密码;
	printf("登录->请输入账号：");
	带检测输入(账号.文本型, 3);
	账号.整数型 = 用户_ID查询(账号.文本型);//匹配用户数据
	if (账号.整数型 == -1) { printf("该账号不存在，请联系管理员进行纠正！\n"); system("pause"); system("cls"); return -1; }
	printf("登录->请输入密码：");
	带检测输入(密码.文本型, 3);
	if (strcmp(密码.文本型, 用_户[账号.整数型].密码)) { printf("登陆失败，密码错误！\n"); system("pause"); system("cls"); return -1; }
	printf("登陆成功！\n");
	system("pause"); system("cls");
	登录用户ID = 账号.整数型;
	sprintf(账号.文本型, "title %s", 用_户[登录用户ID].账号);
	system(账号.文本型);
	return 0;
}//登陆失败返回-1
int 菜单(void) {
	临时数据 操作;
	printf("菜单\n[1]用户信息\t[2]课程信息\n[3]系统日志\t[0]退出\n请输入数字继续操作:");
	带检测输入(&操作.整数型, 1);
	system("cls");
	switch (操作.整数型) {
	case 1:while (!用户信息()); break;
	case 2:while (!课程信息()); break;
	case 3:while (!查看日志()); break;
	case 0:return 1; break;
	}
	system("cls");
	return 0;
}
int 用户信息(void) {
	临时数据 操作;
	printf("用户信息\n");
	switch (用_户[登录用户ID].权限类型) {
	case 1:
		printf("[1]浏览用户\t[2]搜索用户\n[3]导入用户\t[4]导出用户\n[5]修改密码\t[0]返回\n请输入数字继续操作:");
		带检测输入(&操作.整数型, 1);
		system("cls");
		switch (操作.整数型) {
		case 1:while (!浏览用户()); break;
		case 2:搜索用户(); system("cls");  break;
		case 3:导入用户(1); 数据校验(0); system("pause"); system("cls"); break;
		case 4:导出用户(1); break;
		case 5:while (修改密码(登录用户ID)); break;
		case 0:return 1;
		default:printf("操作非法，请重新输入！"); system("pause");  system("cls"); return -1;
		}
		break;
	case 2:
		printf("工号:%s\t姓名:%s\n[1]我的学生\t[2]搜索学生\n[3]修改密码\t[0]返回\n请输入数字继续操作:", 用_户[登录用户ID].账号, 用_户[登录用户ID].姓名);
		带检测输入(&操作.整数型, 1);
		system("cls");
		switch (操作.整数型) {
		case 1:while (!我的学生(登录用户ID)); break;
		case 2:搜索用户(); system("cls"); break;
		case 3:while (修改密码(登录用户ID)); break;
		case 0:return 1;
		default:printf("操作非法，请重新输入！"); system("pause");  system("cls"); return -1;
		}
		break;
	case 3:
		printf("学号:%s\t姓名:%s\n[1]修改密码\t[0]返回\n请输入数字继续操作:", 用_户[登录用户ID].账号, 用_户[登录用户ID].姓名);
		带检测输入(&操作.整数型, 1);
		system("cls");
		switch (操作.整数型) {
		case 1:while (修改密码(登录用户ID)); break;
		case 0:return 1;
		default:printf("操作非法，请重新输入！"); system("pause"); system("cls"); return -1;
		}
		break;
	}
	return 0;
}
int 课程信息(void) {
	临时数据 操作;
	printf("用户信息\n[1]浏览课程\t[2]搜索课程\n");
	switch (用_户[登录用户ID].权限类型) {
	case 1:
		printf("[3]导入课程\t[4]导出课程\n[0]返回\n请输入数字继续操作:");
		带检测输入(&操作.整数型, 1);
		system("cls");
		switch (操作.整数型) {
		case 1:while (!浏览课程()); break;
		case 2:搜索课程(); system("cls"); break;
		case 3:导入课程(1); 数据校验(0); system("pause"); system("cls");  break;
		case 4:导出课程(1);  break;
		case 0:return 1;
		default:printf("操作非法，请重新输入！\n"); system("pause"); system("cls"); return -1;
		}
		break;
	case 2:case 3:
		printf("[3]我的课程\t[0]返回\n请输入数字继续操作:");
		带检测输入(&操作.整数型, 1);
		system("cls");
		switch (操作.整数型) {
		case 1:while (!浏览课程()); break;
		case 2:搜索课程(); system("cls"); break;
		case 3:while (!我的课程(登录用户ID)); break;
		case 0:return 1;
		default:printf("操作非法，请重新输入！\n"); system("pause"); system("cls"); return -1;
		}
		break;
	}
	return 0;
}
int 退出(void) {
	导出课程(0);
	导出用户(0);
	free(课_程); free(用_户);
	fclose(课程数据); fclose(用户数据);
	printf("感谢使用本软件，欢迎下次再见！\n");
	system("pause");
	system("cls");
	return 0;
}