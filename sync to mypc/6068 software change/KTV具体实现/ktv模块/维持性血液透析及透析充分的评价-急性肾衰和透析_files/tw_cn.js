var Default_isFT = 0		//Ĭ���Ƿ��壬0-���壬1-����
var StranIt_Delay = 100 //������ʱ���루�������Ŀ��������ҳ�����������ֳ�����

function StranText(txt,toFT,chgTxt)
{
	if(txt==""||txt==null)return ""
	toFT= toFT==null ? BodyIsFt:toFT;
	var a ="��";
	var b ="��";
	if(! toFT)  a 	="��";
	if(! toFT)	b ="��";
	if(chgTxt) txt	=txt.replace(a,b);
//	if(chgTxt) txt	=txt.replace ( (  ), (toFT ? "��" : "��" ));
	if(toFT){return Traditionalized(txt)}
	else {return Simplized(txt)}
}
//ת������ʹ�õݹ飬�������ı�
function StranBody(fobj)
{
	if(typeof(fobj)=="object"){var obj=fobj.childNodes}
	else 
	{
		var tmptxt=StranLink_Obj.innerHTML.toString()
		if(tmptxt.indexOf("��")<0)
		{
			BodyIsFt=1
			StranLink_Obj.innerHTML=StranText(tmptxt,0,1)
//			document.getElementById("StranLink").title=StranText(document.getElementById("StranLink").title,0,1)
		}
		else
		{
			BodyIsFt=0
			StranLink_Obj.innerHTML=StranText(tmptxt,1,1)
//			document.getElementById("StranLink").title=StranText(document.getElementById("StranLink").title,1,1)
		}
		setCookie(JF_cn,BodyIsFt,7)
		var obj=document.body.childNodes
	}
	for(var i=0;i<obj.length;i++)
	{
		var OO=obj.item(i)
		if("||BR|HR|TEXTAREA|".indexOf("|"+OO.tagName+"|")>0||OO==StranLink_Obj)continue;
		if(OO.title!=""&&OO.title!=null)OO.title=StranText(OO.title);
		if(OO.alt!=""&&OO.alt!=null)OO.alt=StranText(OO.alt);
		if(OO.tagName=="INPUT"&&OO.value!=""&&OO.type!="text"&&OO.type!="hidden")OO.value=StranText(OO.value);
		if(OO.nodeType==3){OO.data=StranText(OO.data)}
		else StranBody(OO)
	}
}//
function JTPYStr(){
	var sim	='�����רҵ�Զ�˿������ɥ���ܷ���Ϊ����ô��������ϰ�����������ڿ���ب�ǲ�Ķ�����ڽ����ز����Ǽ����Ż����ɡΰ����������α������Ӷ�����½�����ȿ�٭ٯٶٱٲ��ٳ��ծ�������ǳ����ϴ��ж��������������������ڸԲ�д��ũڣ��������������������ݼ�����ƾ��������ۻ������մ�ɾ���i�ٹ����ܼ��н�����Ȱ����۽����������ѫ����������ҽ��Э����¬±����ȴ�᳧������ѹ���ǲ������ó������ز΅���˫�������Ҷ��̾ߴ�����������Ķ�������߼߽Ż߿��Ա��Ǻ��ӽ���������������������������ܻ�������Ӵ��y��|������������������Х����࿺�������������������԰��Χ���ͼԲʥ�۳��໵���̳�ް����׹¢�����ݿ����ѵ��눙����������������ǵ��Gǽ׳���Ǻ��״�������ͷ��ж���ۼ�ܽ���ױ���������橽�¦�欽�����测OӤ���������������ѧ������ʵ�����ܹ������޶�Ѱ���ٽ�����Ң��ʬ��������������������᫸���ᰵ�����ᴿ��N�Ͽ�i����������ո�ɍ��������۹��ϱ�˧ʦ�������Ĵ�֡����������᥸ɲ���ׯ��®�п�Ӧ���ӷώ��޿������������䵯ǿ�鵱¼���峹�������������黳̬���������������������Ҷ�������������������������ҳͱ�㫲ѵ�����㳷��Ը��\�����������Ϸ�ս꯻�����Ǥִ����ɨ���Ÿ����ҿ�������������£��ӵ��š�����ֿ�Β���̢Ю�ӵ��������Ӓ�����񻻵�����°������������������§��Я�����ҡ��̯������ߢߣߥ���ܵ�����ի쵶�ն���޾�ʱ���D���o�Խ�ɹ�����������������ӻ�ɱ��Ȩ������追ܼ���������������ǹ���ɹ�������դ��ջ���ж����������������������嵵����������׮�Η���������������¥���鷘������ƺ���ӣ�ͳ��������ݻ��ŷ���������������Ź��챱ϱ�ձ�������뵻㺺����������û��Ž���ٲכh�����mŢ����������к�������������ǳ����䥛��ǲ�䫼�䯛����Ũ䱛�Ϳӿ���������Л��������ɬ��Ԩ�����½���������������ʪ�����Ӝ�������������������б�̲����������ΫǱ���������������ֲ��¯�����������˸�������̷����ǻ��̽��Ȼ����������ְ�ү���ǣ������״�����̱���A������ʨ����������������è���̡��_�`���⻷�֫o�����巩�竚���Q��������������걵续�������ű�����ߴ�������Ӹ�������컾������}������̱���Ѣ�񳰨����յ�μ�ǵ���������������������������������ש���������������n��˶���ͳ}�~ȷ�ﰭ���׼�������t����������»����ͺ���ֻ��ƻඌ��˰�����������Ҥ���ѿ��������������ȼ���������ɸ�Y�ݳ�ǩ����������������¨���������������������������׽�����������������Լ����������γ������ɴ���������ڷ�ֽ�Ʒ�����Ŧ������������ϸ֯��称������ﾭ窰��޽������笻��Ѥ������ͳ�篾��������м�簼���������糴�����ά��緱��������������׺��罼������翼�������綶��������Ļ����Ʊ���Ե�Ƹ����Ƿ����ɲ���������������ӧ���������������������ٽ�������޷��������������������ʳ�����ְ���������೦����������в��ʤ�������ֽ�����������ŧ���������������N�������������H��������������ܳ�ս���ܼ��«��έ�����ɲ�������ƻ����������뾣���Q���������������ٻ�����ӫݡݣݥ��ݤݦݧҩݰݯ����ݪݫݲ��ݵӨݺݻ�[��өӪ�����������޽���������������Ǿ������ޭ��޴޻޺²���������Ϻ�ʴ������������������������������Ӭ���Ы����΅���]���β��������Є��Ϯ�Bװ���T���Ͽ����������[�����_�������������������`��������������Ԁ����ڥ�ƶ����ϼ�ڦڧ����ڨ��ѵ��Ѷ��ך����کڪ��ګ������כ�Ϸ���þ�֤ڬڭ����ʶלթ����ڮ�ߴ�ڰگם��ڱڲڳ��ڴʫڵڶ����ڷ����ڸڹ��ѯ��ں�����ڻڼמ������ڽ��ھ�ջ�ڿ˵����������ŵ���·̿�����˭�ŵ�����׻��̸��ı�ȵ�����г����ν�����β�������������נ������лҥ����ǫ�׽�á������̷������������Ǵ���߹��k���긺�O�������Ͱ��˻��ʷ�̰ƶ�Ṻ���ᷡ�����������ܴ�ó�Ѻ������޼ֻ�����¸���������������޸��������ʹ��P�Q���������R׸��׬���������S����Ӯ���W�Ը�������Ծ�����ȼ��Q��������ӻ������������������������������a��ת���������������������������������������b�����������������Թ����c��ꣷ����d����ԯϽշ���ꥴǱ����ɴ�Ǩ�����˻����ԶΥ�������ɼ���ѡѷ��������ң����������������ۣۧۦ֣۩۪�ǵ����N������������⠼����������붤��������ǥ����蕷����������藸����Ѷ۳����Ʊ�������Կ�վ��ٹ���������ť����Ǯ��ǯ�ܲ������������������������������Ǧí������������������������������ͭ��������ա��ϳ���������������綠�ҿ������������������������ﭳ��������ﲷ�п���������������ê���������സ׶���������Ķ������������A������������������B���Ͷ�þ���C�����D�����������ָ�����F�������G�޾��������H���������������������������I�����������J�ⳤ���������\���ʴ��������ȼ�������բ�ֹ����������]��������������^���������������ղ������_���������`�����a��������׼�½¤���������������������ѳ���������ù����������������Τ��킺������ҳ��������˳������˶���������Ԥ­���ľ����F���G���Ƶ�H����Iӱ�����J���ն�������K����ȧ���r�s����t��u�vƮ�쮷�����𗼢����������������α�����¶�����������������������ڹ�������Ȳ��@���A����������������Ԧ��ѱ�����R��¿��ʻ�������פ��������������S�����溧���T������U�V�����������W�X��ƭ���Yɧ����������������������Z������������������������³�����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������@��𯼦����\Ÿѻ�]�����Ѽ�^���_��ԧ�`��������a�b�����c���������������ȵ�����d�����e���f�g�h���i�����������k���l�m�n�o�Ϻ��p�����������������rӥ���s���t����������d������������ػ������촳�����������������������ȣ���������־����ֻ��ϵ����û��������׼�ӱ��иɾ���ƴ';
	return sim;
}//
function FTPYStr()
{
	return '�f�c�h���I���|�z�G�ɇ��ʂ����S�R�����e�N�x���������l���I�y���̝녁����a���H�C���|�H�ā��}�x���r����ⷕ����ゥ�����t����΁��w�N��L�b�H�e�ɂȃS�~���z�R�����z�������A��E�f�����������������h�m�P�dƝ�B�F�σȌ��Ԍ�܊�r�V�T�n�Q�r���Q�D���R�p���C���P�D�{�P������c�����t�����h�e�}�q�������������������k�Մ�ӄ�ńڄ݄��̈́��Q�T�^�t�A�f���u�R�u�P�l�s���S�d�х��������������B�N���P�h���a�^�p�l׃���B�~̖�U�\�n�ᇘ�Ά�w�� ���Ǉ`�҇I���h�T�J�܆�ԁ�U�����z߸�j�y��푆��}�^�􇂇W�������чO�߇Z����r����K�݇��m�Ӈc�[���D���������u�ڇ������o�F�@��������D�A�}������ĉK�ԉ��ȉΉ]�����ŉŉ������s�׉|�������N�߉P�_��|���q���Ϡ������؉�̎���}���^�F�A�Z�Y�J�^���W�y�D�����������K��I�ƋɌD�ʋz������ȋ����܋�ԋߌO�W�\�������������m���e���������ی����m����ƱM�ӌڌόÌٌҌՎZ�q�M�獏�s�S���u�X�[���h�G�F�{�A�����n�����M��V�􍣍⼹�p얎��Ŏ����������Î����͎Ύ������L�ցK�V�f�c�]�T�쑪�R���U�F�[�_�����������������w��䛏����؏��ƶR���ԑn���ёB�Z���Y����z�������ّ����Q�Ð�Ő�������ґa���@�֑K�͑v�ܑM���T���C���|ؑ��𑿑Б��ߑ����������L�̔U�ВߓP�_�ᒁ���������o����M�n����r�Q�ܓ�쓴�����钶�ϓ��ג�D�]�͓Ɠp��Q�v���ӓ�S�ۓ���������v�R�����y�z�d�[�u�P���t�Δf�X�]�x�\���������S���Y�ؔ��o�f�r�番�ҕ����@�x��ԕϕ������ᄞ�g��C���s���l���q�ܘO�����З����g�������n�����f�d�Ř˗����ɗ������ژ䗫�ә藨����E�n�����u�����������z����������E�Ǚ���Ιx�������M�{�љ����������_�g�e�W���{����������������ݞ�����֚Кښ���菡�h�@�����e�ϛ]���a�r�S��t��������I�͞{�o�T�a���ɛܝ����D�ќ\�{�����۝�y�ҝ��g�I���G�❡���T�������Z�i���u�ݜo�읙���q���՜Y�O�n�^�u�ƝO�c�B���[���񝢞R�s�U���L�������M�]�V�E���I���˞E�u�t���H���z���|�l������`�ĠN���t�������c����q���N�T��������Z�C�a�៨�F�c������۠����Ӡ��ޠُ���E�w�q�N���������M�{���b�z�s���C�J�M�i؈�o�I�H�^�m�����|�h�F���t�z�k�m���c�q�\�I�������a�v�����Y�T늮����ܮ��X�����O��󜯏�������b�d�W�{�A���B�V�D�������T�c�a�`�]�_�dğ�}�����K�}�O�w�I�P�g�{�������A���m���C���\�V�X�a�u�����^�Z�a�[�A�����T�����o���_�|�K���~�A���L�Y�B�[���\���A���U�x�d���N�e�Q�x�v�����d���w�F�`�[�G�Z�C�Q�]�M�Q���V�S�P�a�{�\�e�B�`�Y���~�I�����U�j�D�X�j�������t�@�h�f�[�ei�g�c���S�Z�R�f�o�{��m�u�t�q�w�v�s���w�k�o�x�������������V�{���v�]�����y�������~�����C�X�����M�������K�U�O�E�I�B�[���H���q�Y�f�@�x�W�L�o�k�{�j�^�g�y�������C�����d�^�����w�c�x�m�_�p�b�y�i�K�S�d�R���I�T�^�J�C�`�U�G�Y�l�~�|�}���|�������Z�D���E���������P�����|�������N�`�d�b�p�\�c�p�r�O�V�_�~�z�w�t�s�����i�������\�`�R�Q�U�y���W�_�P�T�`�b�u�w�N�P�E�g�e�u�@�C�c�w�d�I�[Û�{đ�ٖV�L�FÄ�z�}Ē�vĚ�Xē�L�_Ó�TĘ�D�Z�s�|ā�t�e�vĜ�NݛŜŞœ�A�D�W�Hˇ���d�Gʏ�JɐȔ˞�{�O�n�r�K���O�o�d�\�L���O�G�]�R�vʁɜ�w�C�jʎ�sȝ��Ο��n�|�p�a�{ȇȒˎ�Wɉ�Rɏ�P�n�W�@�~���Lɔ�E�}Ξ�I�Mʒ�_�[�rʉ�Y�V�{�E�yʚ�v��N�`�A�@�I�N˒���\̔�]̓�x�A�l�m�rϊ�gρΛ�Qϖ͘�MϠ�|�U�U͐�u·ϓ͑΁Ϟω�X�sϐ�Nϔ�Q�\�D���a�rЖ�\��ы�m�u�U�b�dтў�cѝ�M�@�h���wҊ�^ҍҎҒҕҗ�[�X�JҠ�]�C�D�M�P�U�x�|�zׄ�u�`ӅӋӆӇ�J�Iӓӏӑ׌ӘәӖ�hӍӛӕ�v�M֎�nӠ�G�SӞՓ�K�A�S�O�L�E�C�b�X�u�{�R�w�p�V�\�g�a�~�x�t�v�g�r�E�CԇԟԊԑԜ�\�DԖԒ�QԍԏԎԃԄՊԓԔԌ՟Ԃ�p�]�_�Z�V�`�a�T�d�N�f�b�OՈ�TՌ�Z�xՎ�u�nՆ՘�lՔ�{�~ՏՁ�rՄ�x�\�Rՙ�e�G�C�o�]�^�@�I�X׋�J�O�V�B�i՛՚փו�q�x�{�r՞�t�k֔֙ֆ�vև�T�P�S׎�V�Hח�l�d׏�Y�rؐؑؓؒؕؔ؟�t���~؛�|؜؝ؚ�Hُ�A؞�E�v�S�B�N�F�L�J�Q�M�R�O�\ٗ�Z�V�D�U�T�E�Y�W�B�g�c�l�d�xـ�V�H�p�n�F�k�s�r�yهوٍَِّ٘�Iדٚٛ٠�A�M�X�w�sڅڎ�O�Sۄە�V�`�J�Eۋ�]�Q�x�Pۙ�W�U�bۘ�X�f�k�g�|܇܈܉܎܍ܐ�Dܗ݆ܛ�Z�M�V�_�S�T�Wܠ�F�]�U�p�Y�d�e�I�c�b�`�^�m�o�v݂݅�x݁�y݈�z�wݏݗ݋ݜݔ�\�@ݠݚ�A�H�O�o�q�p߅�|�_�w�^�~�\߀�@�M�h�`�B�t߃ޟ�E�m�x�d�fߊ߉�z�b�����w�]�u�����d�S�P�����i�B�y���j�w�u�����Y���b��Y��������Q�T�A��l�C��{�S��O�]�}�b��g�n�R�c�^��k�j耚J�x�u�^��[��^�o�Z��X�`�Q�����O���X��f�g����F�K��p�U�T��C�B�G��I�o�D��s�B�e�y�t��K�~�X�H��z����b�A��f��x��t��P�C�q��P�|�|�@�y��T���o�n���H�N�i��{�z���~�n�S�s�h�\����J�R�Z�u�|�H��N�e�^�W��K�_�a�d��N�F�\�v���U�V�I��i�O��}�|�I�J���@�R��}��D�X��V�U�t���n�k�����y��^��g�S�M��a�O�R�C���B����h�u��|���j��Z�D�G�C��O�d�s�n��L�T�V�W�Z�\�]���J�c��e�b�g�h�`���l�[�|�Y�}��G�y�w�u��b���A����]�����U�@��T���H�D�F�I�R�X�����A�H��]�����E�U�S�[�`�h�y�rׇ�Z�F�V�q�\�n�o�v�^�X�d�x�f�g�h�n�t�y�w����������B��D���C��@�A�B�I�H�i�R�a�c�M�}���W�U�l�_�j�h�e�f�w�}�����~�D�����h���A�E�L�^�Q�R�S�Z�\�`�_�d�h�j�j�w����}����h��q������T������D���A��E��F��G�L�I�N�H�K�R�Q�W�^�l���k�t��v�x�o�s�}�~�z������R�S�W�Z�Y��_�g�H�z����x�|�v��w�{�A�~��R�������Q�P�G��H��E�U�T�S�K�R���_�s�j�}�\��t�q�~�����E�K�L�J�t�y�x�W�|�u�~������������E�G�T�|�O�W�V�N�U�c�Q�T�q�^�w�n�b�j�f�`�d�q�o�r�~���\���~�����������������z�a�����N���O�E�H�K�A�F�T���L�Y�X���a�l�s�l�[���g�w�{�q�v�m�e�F�c�������������������B�L�M�����I�@�Z�X�[�V�s�h�k�g�B�F�u�S�Q�O�t�f�I�d�c�����R���{���o�|�z�x���r���v���������@���[���M�P�Z�N�]�Z�O���Y�^�o���g�A�l�i�k�����t���������X�\�B�F�g�_�O�V�W�^�Y�Q�s�W�p�w�����������D���I�L�X�U�z�����S�Z�s�t�o�w�x�{����B�O�R�W�X�Z�[�]�e�g�_�f�b�l�r�p�x�}���������I�u���b�e�S���Ӈ��L�\�I��犏��fǬ���K��';
}//
function Traditionalized(cc){
	var str='',ss=JTPYStr(),tt=FTPYStr();
	for(var i=0;i<cc.length;i++)
	{
		if(cc.charCodeAt(i)>10000&&ss.indexOf(cc.charAt(i))!=-1)str+=tt.charAt(ss.indexOf(cc.charAt(i)));
  		else str+=cc.charAt(i);
	}
	return str;
}
function Simplized(cc){
	var str='',ss=JTPYStr(),tt=FTPYStr();
	for(var i=0;i<cc.length;i++)
	{
		if(cc.charCodeAt(i)>10000&&tt.indexOf(cc.charAt(i))!=-1)str+=ss.charAt(tt.indexOf(cc.charAt(i)));
  		else str+=cc.charAt(i);
	}
	return str;
}

function setCookie(name, value)		//cookies����
{
	var argv = setCookie.arguments;
	var argc = setCookie.arguments.length;
	var expires = (argc > 2) ? argv[2] : null;
	if(expires!=null)
	{
		var LargeExpDate = new Date ();
		LargeExpDate.setTime(LargeExpDate.getTime() + (expires*1000*3600*24));
	}
	document.cookie = name + "=" + escape (value)+((expires == null) ? "" : ("; expires=" +LargeExpDate.toGMTString()));
}

function getCookie(Name)			//cookies��ȡ
{
	var search = Name + "="
	if(document.cookie.length > 0) 
	{
		offset = document.cookie.indexOf(search)
		if(offset != -1) 
		{
			offset += search.length
			end = document.cookie.indexOf(";", offset)
			if(end == -1) end = document.cookie.length
			return unescape(document.cookie.substring(offset, end))
		 }
	else return ""
	  }
}
//����������������ã���ͨ��onclick��ĳ��span��id���ȥ�����ӣ�artdetails�еİ������
function doStranLink(objname){
	obj	=document.getElementById(objname);
	return doStranLinkObj(obj);
	}
//�����������һ����ͬС�죬���������ʹ�õĲ��Ƕ�����������ֱ���Ѿ�ȡ�����Ķ���	
function doStranLinkObj(obj){
	if (obj!=null){
		obj.innerHTML	=StranText(obj.innerHTML,1,1);
		return true;
	}else{
		return false;
		}	//end if	
	}
//��������Զ�ѭ��������û��id��StranLink0��StrankLink100�Ķ��󣬣�����id��<span><div> ֮�࣬id��StranLinkxxx)���оͰ����������ת�ɷ��塣����м���ֶϵ����ͻ���ֹ���������ԣ����ӣ�test/testtwch.jsp
var local	=navigator.userLanguage;
if(local=='zh-tw' || local=='zh-hk' ||local=='zh-mo'){
	doarticlecn();
}else if(navigator.appName=='Netscape' && navigator.appVersion.indexOf("zh-TW")!=-1){
	doarticlecn();
}else{
	var	url	=top.location.href;
	if(url.indexOf("charset=tw_big5")!=-1){
	doarticlecn();
	}
}

function doarticlecn(){
	var obj	=document.getElementById("topic");
	if(obj!=null) doStranLink('topic');
	var obj1	=document.getElementById("contents");
	if(obj1!=null) doStranLink('contents');

	var objs	=new Array("topic","contents","topmenu","blogmenu","catesmenu","title","topiclist","bbslist","titlelist","right","left","center","middle","bottom","head","searchform");
	for(var i=0;i<objs.length;i++){
		var obj	=document.getElementById(objs[i]);
		if(obj!=null) doStranLinkObj(obj);
		}

var StranLink_Obj=null;
for(var num=0;num<=100;num++){
	var objname	="StranLink"+num;
	if (! doStranLink(objname)){
	break;
	}	//end if
}//end for
}



/*
	if (StranLink_Obj!=null){
	//	var JF_cn="ft"+self.location.hostname.toString().replace(/\./g,"")
	//	var BodyIsFt=getCookie(JF_cn)
	//	if(BodyIsFt!="1") BodyIsFt=Default_isFT;
		with(StranLink_Obj){
	//		if(typeof(document.all)!="object"){ 	//��IE�����
	//			href="javascript:StranBody()"
	//		}else{
	//			href="#";
	//			onclick= new Function("StranBody();return false")
	//		}
	//		title=StranText("����Է������ķ�ʽ���",1,1)
		innerHTML=StranText(innerHTML,1,1)
		}//end with
	//	if(BodyIsFt=="1"){setTimeout("StranBody()",StranIt_Delay)}

*/