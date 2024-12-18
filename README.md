目□□录
一□功能设计

1.1□ 实验目的……………………………………………………………………
1.2□ 主要功能 ……………………………………………………………………
1.2.1□ 管理员功能 ………………………………………………
1.2.2□ 会员功能 …………………………………………………
1.3□ UML类图…………………………………………………………………………
1.4□ 运行演示示例…………………………………………………………………

2□实验环境
2.1□运行环境 ………………………………………………………………………
2.2□编程语言………………………………………………………………………… 

3□技术细节
3.1□结构设计 ………………………………………………………………… 
3.2□系统架构设计 ………………………………………………………………… 
3.3□系统功能模块设计…………………………………………………………… 
3.4□设计亮点 ………………………………………………………………… 
3.5□函数功能和类实现亮点 ……………………………………………………………… 


4□开发心得
4.1□收获 ………………………………………………………………………………
4.2□反思 ……………………………………………………………………………… 
 





  1□健身俱乐部用户系统实验报告
一□功能设计

1.1□实验目的
本实验旨在设计并实现一个面向管理员和会员的健身俱乐部用户系统，代码层面可以方便添加新俱乐部类型，具体实现层面可以接受俱乐部之间的不同特色，满足用户对不同类型俱乐部的需求，同时能够实现对俱乐部信息、会员信息、会员卡信息、教练信息（针对 ClubA）、健身活动信息（针对 ClubC）的管理，包括信息的录入、查询、修改、删除以及相关业务逻辑的处理，如会员登录、注册，会员卡操作，健身活动组织等，以提高健身俱乐部的运营管理效率。

1.2□主要功能
健身俱乐部用户系统主要功能是作为管理员会员一体化的管理工具，为管理员管理俱乐部和会员，会员管理个人信息和个性处理提供便利。为此，该系统需要实现以下功能：


1.2.1□管理员功能
以通过俱乐部管理系统的密码（默认1234567890），可以添加，删除，修改，查找，排序，清空俱乐部；
选择特定的俱乐部登录，通过俱乐部特定的管理员账号密码检验（可以通过Club.txt获取管理员账号密码），可以显示此种类型俱乐部的所有会员信息，删除，修改，查找，排序，清空会员信息，并相应同步于文件，管理员可后台查看信息；
管理员可通过文件输入教练团队和活动信息，从而更新信息。

1.2.2□会员功能
会员可以查看所有俱乐部及其介绍，选择特定俱乐部，可以进行登录注册，登录成功后，对于每个俱乐部会员都有基本的权限，可以显示，修改个人信息，办卡，续费，消费结算，退卡，也有各自俱乐部的特色权限，如A型俱乐部有训练方案制定，教练团队展示的会员权限，C型俱乐部有活动信息显示的会员权限。
同时为每个用户创建独立的会员卡信息文件，便于维护。


1.3□UML类图


1.4□运行演示示例


(c)

图2.1□初始界面

(d)

图2.2□选择2.显示俱乐部

(e)

图2.3□选择1.选择俱乐部


(f)

图2.4□选择2.A型：潮动健身俱乐部

(g)

图2.5□选择1.继续登录

(h)

图2.6□登录潮动健身俱乐部成功后

(i)

图2.7□登录锐健健身俱乐部成功后

(j)

图2.8□登录优体健身俱乐部成功后

(k)

图2.9□登录潮动健身俱乐部的管理员权限成功后


二□实验环境
2.1□运行环境：Visual Studio 2022

2.2□编程语言：C++


三□技术细节

3.1□结构设计


3.2□系统架构设计
本健身俱乐部管理系统采用面向对象的设计思想，主要包含以下几个核心类：
 （一）Card类
- 功能描述：该类用于表示会员卡的相关信息。
- 属性：
    - Cid：会员卡的唯一标识，类型为string。
    - Ctype：卡的类型，用short类型表示。
    - CexpirationDate：卡的有效期，string类型。
    - Cbalance：卡内余额，double类型。
    - consumptionTime：消费时间，string类型。
- 方法：
    - Card(string Cid, short type, string expirationDate, double balance, string consumptionTime)：构造函数，用于初始化会员卡对象的各个属性。
    - showCardInfo()：用于展示会员卡的详细信息，具体实现[此处留空]。
    - ~Card()`：析构函数，用于释放会员卡对象占用的资源。

 （二）ClubA类
- 功能描述：继承自Manager类，是特定类型俱乐部（ClubA）的管理类，除了通用的俱乐部管理功能外，还包含与私人教练相关的功能。
- 属性：
    - trainers：存储PrivateTrainer对象的向量，用于管理俱乐部的私人教练团队。
    - m_traNum：记录教练的数量，int类型。
    - m_traFileIsEmpty：表示教练信息文件是否为空的布尔值。
- 方法：
    - init_Tra()：用于初始化俱乐部的私人教练信息。
    - ClubA(int type, int id, string name, int rank, string m_managerAccount, string m_managerPassword)：构造函数，初始化俱乐部的基本信息并继承自Manager类的构造函数。
    - 继承自Manager类的一系列虚函数，如showInfo()、showMenu()等，用于俱乐部信息展示、菜单显示等通用功能。
    - displayTrainer()：用于展示俱乐部的私人教练信息。
    - createCustomTrainingPlan(int index)：为指定会员（通过索引）创建定制训练计划。
    - displayTrainingPlan(int index)：展示指定会员（通过索引）的训练计划。

 （三）ClubB类
- 功能描述：继承自Manager类，是另一种类型俱乐部（ClubB）的管理类，主要实现通用的俱乐部管理功能。
- 属性：无特殊额外属性，继承自Manager类的属性。
- 方法：
    - ClubB(int typeint, int id, string name, int rank, string m_managerAccount, string m_managerPassword)：构造函数，初始化俱乐部基本信息并继承自Manager类的构造函数。
    - 继承自Manager类的一系列虚函数，如showInfo()、showMenu()等，用于俱乐部信息展示、菜单显示等通用功能。

 （四）ClubC类
- 功能描述：继承自Manager类，是特定类型俱乐部（ClubC）的管理类，除了通用功能外，还涉及健身活动的管理。
- 属性：
    - events：存储Event对象的向量，用于管理俱乐部举办的健身活动。
    - m_eveNum：记录健身活动的数量，int类型。
    - m_eveFileIsEmpty：表示健身活动信息文件是否为空的布尔值。
- 方法：
    - init_Eve()：用于初始化俱乐部的健身活动信息。
    - organizeFitnessEvent()：组织健身活动的主要方法。
    - ClubC(int type, int id, string name, int rank, string m_managerAccount, string m_managerPassword)：构造函数，初始化俱乐部基本信息并继承自Manager类的构造函数。
    - 继承自Manager类的一系列虚函数，如showInfo()、showMenu()等，用于俱乐部信息展示、菜单显示等通用功能。
    - 私有方法getDefaultLocation(const string& eventType)：根据活动类型获取默认的活动地点。
    - 私有方法notifyMembers(const Event& event)：通知会员报名参加活动。

 （五）ClubManager类
- 功能描述：用于管理多个俱乐部实例，提供对俱乐部的整体操作功能。
- 属性：
    - m_ClubNum：记录俱乐部的数量，int类型。
    - m_ClubArray：存储Manager指针的向量，用于管理多个俱乐部对象（包括ClubA、ClubB、ClubC等）。
    - m_FileIsEmpty：表示俱乐部信息文件是否为空的布尔值。
- 方法：
    - ClubManager()：构造函数，初始化俱乐部管理器对象。
    - showMenu()：显示俱乐部选择菜单。
    - ExitSystem()：退出整个系统。
    - init_Club()：读取文件初始化俱乐部信息。
    - IsExist(int id)：判断指定俱乐部是否存在。
    - save()：保存俱乐部相关信息到文件。
    - authenticate()const：进行身份验证。
    - addClub()：添加新的俱乐部。
    - ShowClub()：展示所有俱乐部信息。
    - DelClub()：删除指定俱乐部。
    - ModClub()：修改俱乐部信息。
    - FindClub()：查找特定俱乐部。
    - SortClub()：对俱乐部进行排序，使用选择排序算法。
    - CleanClub()：清理俱乐部信息。
    - selectClub()：选择进入特定俱乐部系统。

 （六）Event类
- 功能描述：表示健身活动的相关信息。
- 属性：
    - name：活动名称，string类型。
    - type：活动类型，string类型。
    - location：活动地点，string类型。
    - time：活动时间，string类型。
- 方法：
    - Event(string& n, string& t, const string& loc=" ", const string& eventTime=" ")：构造函数，初始化健身活动对象的属性。

 （七）Manager类
- 功能描述：抽象类，定义了俱乐部管理、会员管理、登录等相关功能的接口，供子类继承实现。
- 属性：
    - m_Type：俱乐部类型标识，int类型。
    - m_Id：俱乐部编号，int类型。
    - m_ClubName：俱乐部名称，string类型。
    - m_ClubRank：俱乐部等级，int类型。
    - m_managerAccount：管理者账号，string类型。
    - m_managerPassword：管理者密码，string类型。
    - m_memNum：会员数量，int类型。
    - m_memArray：存储Member指针的向量，用于管理俱乐部的会员。
    - m_FileIsEmpty：表示会员信息文件是否为空的布尔值。
- 方法：
1.void showInfo() - 功能：显示俱乐部的相关信息，如类型、ID、名称和排名。 
2.void showMenu() - 功能：显示俱乐部的菜单，提供用户操作的选项。 
3.void returnBack(bool&)- 功能：返回上一级菜单或退出当前操作，参数 `bool&` 用于控制程序流程，例如是否继续执行。 
4.int IsAccountExist(string)- 功能：检查指定账号是否存在。 
5.void init_Mem() - 功能：初始化会员信息，通常从文件或数据库中加载会员数据。 
6.void save() - 功能：保存当前俱乐部的状态，如会员信息，到文件或数据库。 
7.bool adminLogin(const string& account, const string& password) - 功能：管理员登录验证，检查账号和密码是否正确。 
8.bool userLogin(const string& account, const string& password)- 功能：用户登录验证，检查账号和密码是否正确。 
9.void accountLogin() - 功能：处理用户登录的逻辑。 
10.void accountRegister() - 功能：处理用户注册的逻辑。 
11.void login() - 功能：提供登录界面，让用户选择登录或注册。 
12.void showMenu1() - 功能：显示管理员菜单，提供管理员操作的选项。 
13.void Show_Mem() - 功能：显示所有会员的信息。 
14.void Del_Mem() - 功能：删除会员信息。 
15.IsExist(string id) - 功能：检查指定ID的会员是否存在。 
16.void Mod_Mem()- 功能：修改会员信息。 
17.void Find_Mem() - 功能：查找会员信息。 
18.void Sort_Mem() - 功能：对会员信息进行排序。 
19.void Clean_Mem() - 功能：清空所有会员信息。 
20.void showMenu2() - 功能：显示会员菜单，提供会员操作的选项。 
21.void Show_Sin(int index) - 功能：显示指定索引会员的详细信息。 
22.void Mod_Sin(int index) - 功能：修改指定索引会员的信息。 
23.void Add_Card(int index) - 功能：为指定索引的会员添加新的会员卡。 
24.void renew_Sin(int index) - 功能：为指定索引的会员续费会员卡。 
25.void processConsumption(int index) - 功能：处理指定索引会员的消费。 
26.void cancelCard(int index) - 功能：为指定索引的会员取消会员卡。
这些虚函数定义了 Manager 类的基本行为，而具体的实现则由派生类 ClubA、ClubB 和 ClubC 根据各自的业务逻辑去完成。 

 （八）Member类
- 功能描述：表示会员的相关信息，包括个人基本信息、会员卡信息、健身目标和训练计划等。
- 属性：
    - m_Id：会员的唯一标识，string类型。
    - m_Account：会员账号，string类型。
    - m_Password：会员密码，string类型。
    - m_Name：会员姓名，string类型。
    - m_Age：会员年龄，int类型。
    - m_Gender：会员性别，int类型。
    - m_Phone：会员电话，string类型。
    - m_Address：会员地址，string类型。
    - cardArray：存储Card指针的向量，用于管理会员的会员卡。
    - m_cardNum：会员卡数量，int类型。
    - m_cardFileIsEmpty：表示会员卡信息文件是否为空的布尔值。
    - filename：相关文件名称，string类型。
    - fitnessGoal：会员的健身目标，string类型。
    - trainingPlan：会员的训练计划，存储string的向量。
- 方法：
    - Member()：默认构造函数。
    - Member(string m_Id, string account, string password, string name, int age, int gender, string phone, string address)：带参数的构造函数，初始化会员对象的基本信息。
    - showInfo()：展示会员的详细信息。
    - init_Card()：初始化会员的会员卡信息。
    - IsCardExist(string id)：判断指定会员卡是否存在。
    - cardsave()：保存会员卡信息到文件。

 （九）PrivateTrainer类
- 功能描述：表示私人教练的信息，包括教练姓名和擅长领域。
- 属性：
    - name：教练姓名，string类型。
    - specialties：教练擅长的领域，string类型。
- 方法：
    - PrivateTrainer(const string& n, const string& spec)：构造函数，初始化教练对象的属性。
    - showInfo()const：展示教练的信息，即姓名和擅长领域。
3.3□系统功能模块设计
本系统主要包含以下功能模块：

 （一）俱乐部管理模块
 由ClubManager类实现，包括俱乐部的添加、删除、修改、查询、排序、展示等功能，通过对m_ClubArray向量的操作来管理多个俱乐部实例。

 （二）会员管理模块
 在Manager类及其子类中实现，包括会员的注册、登录、信息展示、查询、修改、删除等功能，通过m_memArray向量管理俱乐部内的会员信息。

 （三）会员卡管理模块
 在Member类和Card类中实现，涉及会员卡的创建、信息展示、余额查询、消费记录、充值等功能，通过Member类中的cardArray向量管理会员的会员卡信息。

 （四）私人教练管理模块（仅 ClubA）
 在ClubA类中实现，包括私人教练信息的初始化、展示，以及为会员创建定制训练计划等功能，通过trainers向量管理俱乐部的私人教练团队。

 （五）健身活动管理模块（仅 ClubC）
 在ClubC类中实现，包括健身活动的初始化、组织、通知会员等功能，通过events向量管理俱乐部举办的健身活动。
3.4□设计亮点

3.4.1 模块化设计 
代码库被组织成多个模块，每个俱乐部（ClubA、ClubB、ClubC）和俱乐部管理器（ClubManager）都有自己的类和功能。这种模块化设计使得代码易于维护和扩展。 
3.4.2 多态性 
系统使用多态性来允许不同俱乐部类共享相同的接口，例如showInfo()、showMenu()和login()等，但每个类可以根据自己的需求实现这些函数。 
3.3.3 封装
每个类都封装了自己的数据和方法，如Member类封装了会员信息和相关操作，Card类封装了会员卡信息和操作。 
3.4.4 文件操作 
系统通过文件操作来持久化会员和俱乐部数据，使用了ifstream和ofstream来读取和写入数据。 同时，当程序运行时希望删除会员，其个人会员卡信息文件也一并删除。
3.4.5 错误处理 
在处理日期和时间的函数中，系统使用了错误处理来确保在获取当前时间或计算未来日期时，如果出现错误，程序能够给出反馈。
文件操作方面保留了文件是否存在，文件是否为空，文件内信息个数的检测，如需检测，可消除注释用于检测。


3.5□函数功能和类实现亮点

3.5.1 generateMemberId() 
功能：生成会员ID。 
技术应用：使用srand和rand函数生成随机数，创建一个以"M"开头，后跟6位数字的会员ID。 
技巧：通过将随机数转换为字符来构建ID字符串。 
3.5.2 getCurrentDate() 
功能：获取当前日期。 
技术应用：使用time和localtime_s函数获取当前时间，并使用strftime格式化日期。 
技巧：使用struct tm来存储日期信息，并将其转换为指定格式的字符串。 
3.5.3 getFutureDate(short validDays) 
功能：计算未来某一天的日期。 
技术应用：在当前日期基础上增加指定天数，并处理月份和年份的溢出。 
技巧：通过调整tm_mday、tm_mon和tm_year成员来处理日期的溢出，确保日期计算的正确性。 
3.5.4 Card类 
功能：管理会员卡信息。 
技术应用：封装了卡的ID、类型、有效期、余额和消费时间。 
技巧：通过构造函数和析构函数管理资源，确保对象的生命周期内数据的有效性和完整性。 
3.5.5 Member类 
功能：管理会员信息和会员卡。 
技术应用：使用向量存储会员卡对象，并提供初始化和保存会员卡信息的方法。 
技巧：通过文件操作来持久化会员卡信息，确保会员数据的持久存储。 
3.5.6 ClubA、ClubB、ClubC类 
功能：代表不同类型的俱乐部，提供特定的服务和会员管理。 
技术应用：继承自Manager类，实现多态性。 
技巧：通过覆盖基类方法来提供特定功能，如showInfo()和login()。 
3.5.7 ClubManager类 
功能：管理所有俱乐部。 
技术应用：使用向量存储俱乐部对象，并提供添加、删除、修改和查找俱乐部的方法。 
技巧：通过authenticate()方法保护敏感操作，确保只有授权用户才能执行特定操作。

四□开发新得

4.1□收获
1.通过本次实验，深刻明白了采用面向对象的编程思想，将系统划分为多个类，每个类负责特定的功能模块，可使得系统结构清晰、易于维护和扩展。
2.同时深入理解了面向对象编程中的类、继承、多态、关联等概念在实际项目中的应用，同时也锻炼了代码设计和组织能力。
3.并且加深了对运行机理的认识，可以灵活应用模板实现数据存储与调用。
4.认识到用户需求的重要性，需要贴合用户的使用体验感去调整代码。
5.代码工作很重要的一部分是耐心地调试代码，一个一个地去除bug。

4.1□反思
1.缺少Qt进行界面设计和数据库的使用，日后需要学习进行补充完善；
2.在文件操作的错误处理方面可能不够完善，系统的界面设计较为简单等，这些问题将在后续的优化和改进中加以解决，以提高系统的稳定性和用户友好性。
