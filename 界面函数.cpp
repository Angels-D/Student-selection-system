int �����ļ�(void) {
	if (�����û�(0) == -1) exit(-1);
	if (����γ�(0) == -1) exit(-1);
	����У��(0);
	system("pause"); system("cls");
	return 0;
}
int ��½(void) {
	��ʱ���� �˺�, ����;
	printf("��¼->�������˺ţ�");
	���������(�˺�.�ı���, 3);
	�˺�.������ = �û�_ID��ѯ(�˺�.�ı���);//ƥ���û�����
	if (�˺�.������ == -1) { printf("���˺Ų����ڣ�����ϵ����Ա���о�����\n"); system("pause"); system("cls"); return -1; }
	printf("��¼->���������룺");
	���������(����.�ı���, 3);
	if (strcmp(����.�ı���, ��_��[�˺�.������].����)) { printf("��½ʧ�ܣ��������\n"); system("pause"); system("cls"); return -1; }
	printf("��½�ɹ���\n");
	system("pause"); system("cls");
	��¼�û�ID = �˺�.������;
	sprintf(�˺�.�ı���, "title %s", ��_��[��¼�û�ID].�˺�);
	system(�˺�.�ı���);
	return 0;
}//��½ʧ�ܷ���-1
int �˵�(void) {
	��ʱ���� ����;
	printf("�˵�\n[1]�û���Ϣ\t[2]�γ���Ϣ\n[3]ϵͳ��־\t[0]�˳�\n���������ּ�������:");
	���������(&����.������, 1);
	system("cls");
	switch (����.������) {
	case 1:while (!�û���Ϣ()); break;
	case 2:while (!�γ���Ϣ()); break;
	case 3:while (!�鿴��־()); break;
	case 0:return 1; break;
	}
	system("cls");
	return 0;
}
int �û���Ϣ(void) {
	��ʱ���� ����;
	printf("�û���Ϣ\n");
	switch (��_��[��¼�û�ID].Ȩ������) {
	case 1:
		printf("[1]����û�\t[2]�����û�\n[3]�����û�\t[4]�����û�\n[5]�޸�����\t[0]����\n���������ּ�������:");
		���������(&����.������, 1);
		system("cls");
		switch (����.������) {
		case 1:while (!����û�()); break;
		case 2:�����û�(); system("cls");  break;
		case 3:�����û�(1); ����У��(0); system("pause"); system("cls"); break;
		case 4:�����û�(1); break;
		case 5:while (�޸�����(��¼�û�ID)); break;
		case 0:return 1;
		default:printf("�����Ƿ������������룡"); system("pause");  system("cls"); return -1;
		}
		break;
	case 2:
		printf("����:%s\t����:%s\n[1]�ҵ�ѧ��\t[2]����ѧ��\n[3]�޸�����\t[0]����\n���������ּ�������:", ��_��[��¼�û�ID].�˺�, ��_��[��¼�û�ID].����);
		���������(&����.������, 1);
		system("cls");
		switch (����.������) {
		case 1:while (!�ҵ�ѧ��(��¼�û�ID)); break;
		case 2:�����û�(); system("cls"); break;
		case 3:while (�޸�����(��¼�û�ID)); break;
		case 0:return 1;
		default:printf("�����Ƿ������������룡"); system("pause");  system("cls"); return -1;
		}
		break;
	case 3:
		printf("ѧ��:%s\t����:%s\n[1]�޸�����\t[0]����\n���������ּ�������:", ��_��[��¼�û�ID].�˺�, ��_��[��¼�û�ID].����);
		���������(&����.������, 1);
		system("cls");
		switch (����.������) {
		case 1:while (�޸�����(��¼�û�ID)); break;
		case 0:return 1;
		default:printf("�����Ƿ������������룡"); system("pause"); system("cls"); return -1;
		}
		break;
	}
	return 0;
}
int �γ���Ϣ(void) {
	��ʱ���� ����;
	printf("�û���Ϣ\n[1]����γ�\t[2]�����γ�\n");
	switch (��_��[��¼�û�ID].Ȩ������) {
	case 1:
		printf("[3]����γ�\t[4]�����γ�\n[0]����\n���������ּ�������:");
		���������(&����.������, 1);
		system("cls");
		switch (����.������) {
		case 1:while (!����γ�()); break;
		case 2:�����γ�(); system("cls"); break;
		case 3:����γ�(1); ����У��(0); system("pause"); system("cls");  break;
		case 4:�����γ�(1);  break;
		case 0:return 1;
		default:printf("�����Ƿ������������룡\n"); system("pause"); system("cls"); return -1;
		}
		break;
	case 2:case 3:
		printf("[3]�ҵĿγ�\t[0]����\n���������ּ�������:");
		���������(&����.������, 1);
		system("cls");
		switch (����.������) {
		case 1:while (!����γ�()); break;
		case 2:�����γ�(); system("cls"); break;
		case 3:while (!�ҵĿγ�(��¼�û�ID)); break;
		case 0:return 1;
		default:printf("�����Ƿ������������룡\n"); system("pause"); system("cls"); return -1;
		}
		break;
	}
	return 0;
}
int �˳�(void) {
	�����γ�(0);
	�����û�(0);
	free(��_��); free(��_��);
	fclose(�γ�����); fclose(�û�����);
	printf("��лʹ�ñ��������ӭ�´��ټ���\n");
	system("pause");
	system("cls");
	return 0;
}