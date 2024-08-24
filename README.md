# ʹ��stm32h743iit6ʵ�ֵ�Linuxϵͳ

## 0. ��ĿԤ��
ʹ��stm32h743iit6ʵ��һ��Linuxϵͳ��ʵ�ֻ�����Linux���ܣ����ļ�ϵͳ�����繦�ܡ�ͼ�ν��湦�ܵȡ���ϵͳ��ʵ�ֻ�����ָ���������GPIO���������ָ���������ͨ����SD����ָ������ļ��Ķ�ȡ��ɸ��ַ���Ĺ��ܡ�

�����ƻ�ָ����£�
- 1. GPIOָ��
1. gpio_init(port, pin, mode, speed, pull) // ��ʼ��GPIO
2. gpio_read(port, pin) // ��ȡGPIO
3. gpio_write(port, pin, value) // д��GPIO
4. gpio_toggle(port, pin) // ��תGPIO
- 2. ����ָ��
3. spi_read(name, data) // ��ȡSPI
4. spi_write(name, data) // д��SPI
5. spi_transfer(name, data) // ��дSPI
7. i2c_read(name, data) // ��ȡI2C
8. i2c_write(name, data) // д��I2C
9. i2c_transfer(name, data) // ��дI2C
11. uart_read(name, data) // ��ȡUART
12. uart_write(name, data) // д��UART
13. tim_setfreq(name, freq) // ���ö�ʱ��Ƶ��
14. tim_upcount(name) // ��ʱ������
15. tim_downcount(name) // ��ʱ������
16. tim_pwm(name, duty) // ��ʱ��PWM
17. otg_read(name, data) // ��ȡOTG
18. otg_write(name, data) // д��OTG
- 3. SD��ָ��
3. mkdir(path)
4. cd(path)
5. ls(path)
6. rm(path)
7. cp(src, dst)
8. mv(src, dst)
9. cat(path)
10. touch(path)
11. echo(str, path)
12. find(path)

## 1. ��Ŀ���
����Ŀ�ǻ���stm32h743iit6ʵ�ֵ�Linuxϵͳ����Ҫ�����У�
- 1.1. ���ڵ��Թ���
- 1.2. �ļ�ϵͳ����
- 1.3. ���繦��
- 1.4. ͼ�ν��湦��
- 1.5. ����ָ���
- 1.6. SD��ָ�������
- 1.7. USB����
- 1.8. ��Դ������
- 1.9. ʱ�ӹ�����

## 2. ��Ŀ�ṹ
```
Appication // Ӧ�ó���
    |---inc // Ӧ�ó���
    `---src // �弶֧�ְ�
    
Command // ָ�
    |---cat // ��ȡ�ļ�
    |---cd // �л�Ŀ¼
    |---cp // �����ļ�
    |---ls // �г��ļ�
    |---mv // �ƶ��ļ�
    `---tree // ��ʾĿ¼��

Core // �����ļ�
    |---inc // ͷ�ļ�
    `---src // Դ�ļ�
    
Drivers // �����ļ�
    |---Kernel // ΢��std��
    |---CMSIS // Cortex-M7�ں�֧��
    `---HAL // Ӳ�������
    
Middlewares // �м��
    |---FreeRTOS // ʵʱ����ϵͳ
    `---FatFS // USB OTG
    
FATFS // fat32�ļ�ϵͳ
    |---App // Ӧ�ó���
    `---Target // Ŀ��BSP
    
RAMFS // ram�ļ�ϵͳ(δ���)
    `---init.d // ��ʼ���ű�
    
Utilities // ����, JPG����
    |---JPEG // JPG����
```

## 3. ��Ŀ����
- [x] 3.1. ���ڵ��Թ���
  - [x] 3.1.1. u_print(fmt, ...)����
- [x] 3.2. �ļ�ϵͳ����
  - [x] 3.2.1. ram_alloc(size)����
  - [x] 3.2.2. ram_free(ptr)����
  - [x] 3.2.3. ram_realloc(ptr, size)����
  - [x] 3.2.5. ram_create()��ʼ��SDRAMΪTLSF�ڴ��
  - [x] 3.2.6. DrT�豸��֧��
  - [x] 3.2.7. SD����FATFS
- [x] 3.3. ����ָ���
  - [x] 3.3.1. lsָ��
- [ ] 3.4. SD��ָ������� TODO
- [ ] 3.5. USB���� TODO
- [ ] 3.6. ��Դ������ TODO
- [ ] 3.7. ʱ�ӹ����� TODO

## 4. ��Ŀ����
���س����, ʹ��Clion�򿪹��̣����úù��̺󣬵�����뼴�ɡ���¼���ΪOpenocd��

## 5. �豸����
FK743M2-IIT6

## 6. ��Ŀ����
Minloha: https://blog.minloha.cn

## 7. ����TODO
- [ ] 7.1. ���SD��ָ�������
- [ ] 7.2. ���USB����
- [ ] 7.3. ��ɵ�Դ������
- [ ] 7.4. ���ʱ�ӹ�����
- [ ] 7.5. �������ָ���
- [ ] 7.6. ���ͼ�ν��湦��
- [ ] 7.8. ������繦��
- [ ] 7.9. ����ļ�ϵͳ����
- [ ] 7.10. ��ɴ��ڵ��Թ���
- [ ] 7.11. ���RAMFS�ļ�ϵͳ
- [ ] 7.12. ���BSP֧��