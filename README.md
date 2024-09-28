# ʹ��stm32h743iit6ʵ�ֵ�Linuxϵͳ

## 0. ��ĿԤ��
ʹ��stm32h743iit6ʵ��һ��Linuxϵͳ��ʵ�ֻ�����Linux���ܣ����ļ�ϵͳ�����繦�ܡ�ͼ�ν��湦�ܵȡ���ϵͳ��ʵ�ֻ�����ָ���������GPIO���������ָ���������ͨ����SD����ָ������ļ��Ķ�ȡ��ɸ��ַ���Ĺ��ܡ�

> ǰ��ʱ����ţ��ȵ�ʱ���ԣЩ��ʱ��дһ��RTOSϵͳ���ٰ�Linuxϵͳ�Ĺ�����ֲ��RTOSϵͳ�С����ڶԸ���FreeRTOS

�����ƻ�ָ����£�
- 1. GPIOָ��
1. gpio_read(port, pin) // ��ȡGPIO
2. gpio_write(port, pin, value) // д��GPIO
3. gpio_toggle(port, pin) // ��תGPIO

- 2. ����ָ��
3. spi_read(name, data) // ��ȡSPI
4. spi_write(name, data) // д��SPI
7. i2c_read(name, data) // ��ȡI2C
8. i2c_write(name, data) // д��I2C
11. uart_read(name, data) // ��ȡUART
12. uart_write(name, data) // д��UART
13. tim_setfreq(name, freq) // ���ö�ʱ��Ƶ��
14. tim_count(name) // ��ʱ������
16. tim_pwm(name, duty) // ��ʱ��PWM

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
- 1.10. �̵߳����㷨

## 2. ��Ŀ�ṹ
```
Appication // Ӧ�ó���
    |---inc // Ӧ�ó���
    `---src // �弶֧�ְ�
    
Command // ָ�
    |---cat // ��ȡ�ļ�
    |---cd // �л�Ŀ¼
    |   |---cd_main.c 
    |   `---cd_main.h
    |---cp // �����ļ�
    |---ls // �г��ļ�
    |   |---ls_main.c 
    |   `---ls_main.h
    |---mv // �ƶ��ļ�
    |---tree // ��ʾĿ¼��
    |---... // ����ָ��
    |---Register.c // ָ��ע��
    `---Register.h // ָ��ע��ͷ�ļ�

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
    
USB_DEVICE // USB�豸
    |---App // Ӧ�ó���
    `---Target // Ŀ��BSP����
    
Utilities // ����, JPG����
    `---JPEG // JPG����
```

## 3. ��Ŀ����
- [x] 3.1. �����ļ�
  - [x] 3.1.1. memctl��
  - [x] 3.1.2. thread��
  - [x] 3.1.3. tlsf�㷨
  - [x] 3.1.4. timer��
- [x] 3.2. �ļ�ϵͳ����
  - [x] 3.2.1. ram_alloc(size)����
  - [x] 3.2.2. ram_free(ptr)����
  - [x] 3.2.3. ram_realloc(ptr, size)����
  - [x] 3.2.5. ram_create()��ʼ��SDRAMΪTLSF�ڴ��
  - [x] 3.2.6. DrT�豸��֧��
  - [x] 3.2.7. SD����FATFS
  - [x] 3.2.8. RAMFS�ļ�ϵͳ
  - [x] 3.2.9. ����CPU
  - [x] 3.2.10. �ļ�ϵͳָ��
  - [x] 3.2.11. kernel_alloc(size)����
  - [x] 3.2.12. kernel_free(ptr)����
  - [x] 3.2.13. kernel_realloc(ptr, size)����
  - [x] 3.2.14. kernel_create()��ʼ���ں�ΪTLSF�ڴ��
- [x] 3.3. ����ָ���
  - [x] 3.3.1. lsָ��
  - [x] 3.3.2. cdָ��
  - [x] 3.3.3. infoָ��
  - [x] 3.3.4. echoָ��
  - [x] 3.3.5. helpָ��
  - [x] 3.3.6. treeָ��
- [ ] 3.4. SD��ָ�������
- [x] 3.5. USB����
  - [x] 3.5.1. USB printf����
  - [x] 3.5.2. USB scanf����
  - [x] 3.5.3. USB�ն�(����Ӧ������)
- [ ] 3.6. ��Դ������

## 4. ��Ŀ����
���س����, ʹ��Clion�򿪹��̣����úù��̺󣬵�����뼴�ɡ���¼���ΪOpenocd������ʹ����arm-none-eabi-gcc��������

## 5. �豸����
FK743M2-IIT6

## 6. ��Ŀ����
Minloha: https://blog.minloha.cn

## 7. ����TODO
- [ ] 7.1. ���SD��ָ�������
- [x] 7.2. ���USB����
- [ ] 7.3. ��ɵ�Դ������
- [x] 7.4. ���ʱ�ӹ�����
- [x] 7.5. �������ָ���
- [ ] 7.6. ���ͼ�ν��湦��
- [ ] 7.8. ������繦��
- [x] 7.9. ����ļ�ϵͳ����
- [x] 7.10. ��ɴ��ڵ��Թ���
- [x] 7.11. ���RAMFS�ļ�ϵͳ
- [ ] 7.12. ���BSP֧��
- [ ] 7.13. ����̵߳����㷨