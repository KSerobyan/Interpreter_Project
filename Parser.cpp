#include <iostream>
#include <fstream>
#include <map>

int var_rett(std::string str);
void var_types(std::string content ,int i);
void type_choose(std::string content );
void integer(std::string content,int count);
void str_var(std::string content,int i);
void strings(std::string content,int count);
void floats_dec(std::string content,int count);
void flo_var(std::string content,int i);
void bools(std::string content,int count);
void bool_var(std::string content,int i);
void loop_dec(std::string content ,int count);
void loop_name(std::string content,int i );
void cond_dec(std::string content ,int count);
void cond_name(std::string content,int i);
void print_dec(std::string content ,int count);
void print_name(std::string ,int i);
int math_ops(int number,int number2,char c);

std::map<std::string,int> map;
std::map<std::string ,std::string>sec_map;

int main(){
	std::string content = "";
	std::ifstream text("interpreter.txt");
	std::string types ="";
    while(std::getline(text,content))
	{ 
 	  	type_choose(content);
    }
       
}
void type_choose (std::string content){
	std::string integs ="integ";
	std::string strins = "strin";
	std::string floats = "floaa";
	std::string boolys = "booly";
	std::string loop = "loop";
	std::string cond = "cond";
	std::string print = "print";
 	
	
	int j=0;
	int count=0;
	for(int i = 0; i < content.length(); ++i)
	{
   	while(content[i] == integs[j])
	{
		++i;
	   	++j;
	   	++count;
   	}

   	if(count == integs.length())
	{
     	integer(content, count);
		return;
    }
   	while(content[i] == strins[j])
	{
   		++i;
   		++j;
   		++count;
   	}

   	if(count  == strins.length())
	{
    		strings(content, count);
    		return;
   	}
   	
	while(content[i] == floats[j])
	{

	   ++i;
	   ++j;
	   ++count;
   	}
   
   	if(count  ==  floats.length())
	{
		floats_dec(content, count);
     	return;
   	}
    
	while(content[i] == boolys[j])
	{
	   	++i;
	   	++j;
	   	++count;
   	}

   	if(count  ==  boolys.length())
	{
     	bools(content,count);
     	return;
   	}
    
	while(content[i] == loop[j])
	{
	   	++i;
	   	++j;
	   	++count;
   	}
   	
	if(count == loop.length())
	{
      	loop_dec(content, count);
     	return;
    }
      
	while(content[i] == cond[j])
	{
	   	++i;
	   	++j;
	   	++count;
   	}
   	
	if(count == cond.length())
	{
      	cond_dec(content, count);
     	return;
	}
    
	while(content[i] == print[j])
	{
	   	++i;
	   	++j;
	   	++count;
   	}
   	
	if(count == print.length())
	{
      	print_dec(content, count);
     	return;
    }
   	else
	{
    	std::cout << "printable type error " <<std::endl;
    	exit(0);
    }
	
	}
}

void print_dec(std::string content,int count)
{
 	std::string var_name = "";
	int j =count;
	int i = count;
	int count1 = 0;
	if(content[i] != ' ')
	{ 
		std::cout << "error"<<std::endl;
		exit(0);
	}
	while(content[i] == ' ')
	{
		++i;

	}	
	
	print_name(content,i);
	
	return;     
}

void print_name(std::string content,int i )
{
    std::string str1 = "";
	while(content[i] == ' ')
	{
		++i;
	}
	
	if(content[i] != '!')
	{
        std::cout << "error: you haven't entered the first ! symbol";
        exit(0);
    }
    
	++i;
	
	if(content[i] != '!')
	{
		std::cout <<"error: there is no 2nd ! symbol";
	}
	++i;
	    
	while(content[i] == ' ')
	{
		++i;
	}
	if(content[i] >= 97 && content[i] <= 122)
	{
	
	}
	else
	{
		std::cout << "printing error" << std::endl;
	    exit(0);
	}
	   	while(content[i] >= 97 && content[i] <= 122 )
		{
	       	str1 += content[i];
	       	++i;
		}

	int ret_var  = var_rett(str1);

    if(ret_var == 1)
	{
        std::cout <<sec_map[str1]<<std::endl;
	}
	
	if(ret_var == 1)
	{
        std::cout <<map[str1]<<std::endl;
	}
		
	if(ret_var == 0)
	{
		std::cout <<"error no variable"<<std::endl;
		exit(0);
	}
    
	str1 = "";
	
	while(content[i] == ' ')
	{
        ++i;
    }
    
	if(content[i] != ';' )
	{
	    std::cout << "error: you have to enter a ; symbol " << std::endl;
	    exit(0);
    }
     
	return; 
    
}
void cond_dec(std::string content,int count)
{
    std::string var_name = "";
	int j =count;
	int i = count;
	int count1 = 0;
	if(content[i] != ' ')
	{ 
		std::cout << "error"<<std::endl;
		exit(0);
	}
	
	while(content[i] == ' ')
	{
		++i;
	}	
	
	cond_name(content,i);
	
	return;  
}

void loop_dec(std::string content ,int count)
{
    std::string str1 ="";
   	std::string var_name = "";
	int j =count;
	int i = count;
	int count1 = 0;
	if(content[i] != ' ')
	{ 
		std::cout << "error"<<std::endl;
		exit(0);
	}
	
	while(content[i] == ' ')
	{
		++i;
	}	
	
	loop_name(content,i);
	
	return;  
}

void cond_name(std::string content ,int i)
{
    
    std::string str1 = "";
    while(content[i] == ' ')
	{
		++i;
	}

    if(content[i] != '!')
	{
        std::cout << "error";
        exit(0);
    }
    
	++i;

	while(content[i] == ' ')
	{
		++i;
	}
	  
	if(content[i] >= 97 && content[i] <= 122)
	{	    
	}
	   
	else
	{
		std::cout << "printing error" << std::endl;
	    exit(0);
	}

		while(content[i] >= 97 && content[i] <= 122 )
		{
	    str1 += content[i];
	    ++i;
		}

    
	int ret_var  = var_rett(str1);

	if(ret_var == 1)
	{
        std::cout <<map[str1]<<std::endl;
	}
	
	if(ret_var == 0)
	{
		std::cout <<"error no variable"<<std::endl;
		exit(0);
	}
       
    while(content[i] == ' ')
	{
        ++i;
    }
	   
	while(content[i] != '!')
	{
	    std::cout << "error '!'" << std::endl;
	    exit(0);
	}
	
	++i;
	    
	while(content[i] == ' ')
	{
		++i;
	}
	   
	while(content[i] != '|')
	{
	    std::cout << "error '|'"<<std::endl;
	    exit(0);
	}
	
	++i;
	
	while(content[i] == ' ')
	{
		++i;
	}
	
	std::cout <<map[str1]<<" cond ";
	
	if(map[str1] == 1 )
	{
		print_name(content, i );
	}
	else
	{
	    std::cout << "error ";
	} 
    
	while(content[i] == ' ')
	{
		++i;
	}
	
    return; 
    
}
void loop_name(std::string content,int i )
{
    std::string str1 = "";
    while(content[i] == ' ')
	{
		++i;
	}
        
    if(content[i] != '!')
	{
        std::cout << "error";
        exit(0);
    }
    
	++i;
	    
	while(content[i] == ' ')
	{
		++i;
	}
	
	if(content[i] >= 97 && content[i] <= 122)
	{
	   
	}
	
	else
	{
		std::cout << "error" << std::endl;
	    exit(0);
	}
	while(content[i] >= 97 && content[i] <= 122 )
	{
	str1 += content[i];
	++i;
	}
	    
	int ret_var  = var_rett(str1);

	if(ret_var == 1)
	{
        std::cout <<map[str1]<<std::endl;
	}
	
	if(ret_var == 0)
	{
		std::cout <<"error no variable"<<std::endl;
		exit(0);
	}
     
    while(content[i] == ' ')
	{
        ++i;
    }
	   
	while(content[i] != '!')
	{
	    std::cout << "error" << std::endl;
	    exit(0);
	}
	
	++i;
	
	while(content[i] == ' ')
	{
		++i;
	}
	
	while(content[i] != '|')
	{
	    std::cout << "error '`'"<<std::endl;
	    exit(0);
	}
	
	++i;
	
	while(content[i] == ' ')
	{
		++i;
	}
	
	std::cout <<map[str1]<<" LOOP ";
	if(map[str1] == 1 )
	{
		print_name(content, i );
	}
	else
	{
	    std::cout << "error ";
	} 
    while(content[i] == ' ')
	{
		++i;
	}
	

    return; 
}
void bools(std::string content,int count)
{
    std::string var_name = "";
    bool x =true;
	int j =count;
	int i = count;
	int count1 = 0;
	if(content[i] != ' ')
	{ 
		std::cout << "error"<<std::endl;
		exit(0);
	}
	while(content[i] == ' ')
	{
		++i;
	}	
		bool_var(content,i);
	
	return;
}

void bool_var(std::string content,int i)
{
	std::string name_of_var ="";
	int count = 0;
	int number  = 0;
	while(content[i] >= 97 && content[i] <= 122)
	{
          name_of_var += content[i];      
		++i;
		++count;
	}
	if(count < 2 )
	{
        std::cout <<" type error" <<std::endl;
		exit(0);
	}
	
	count = 0;

	while(content[i] == ' ')
	{
		++i;
	}
	
	if(content[i] == ';')
	{	
		return;
	}
	
	if(content[i] != '=')
	{
		std::cout << "error  = :"<<std::endl;
		exit(0);
	}
    ++i;
    while(content[i] == ' ')
	{
        ++i;
    }
    
	while(content[i] >= 48 && content[i] <= 57 )
	{
	    number = number *10;
	    number += (content[i] - 48);
	    ++i;
	    ++count;	
	}
	
	if(number != 0)
	{        
	    number =   1;
	}
	else
	{
	    number = 0;
	}
	int j =0;
    std::string fa = "false";
    std::string tr = "true";
    while(content[i] == fa[j])
	{
    	++j;
    	++i;
		++count;
		if(count == fa.length())
		{
			number = 0;	         
		}
	}
	     
	while (content[i] == tr[j])
	{
		++j;
	    ++i;
	  
	    ++count;
	    if(count == tr.length())
		{
	        number= 1;
	    }
	}
	     
    if(count == 0)
	{
		std::cout << "error "<<std::endl;
	    exit(0);
    }
    count = 0;
    while(content[i] == ' ' )
	{
	    ++i;
    }
    
	if(content[i] != ';' )
	{
	    std::cout << "error:you have to enter the ; symbol" << std::endl;
	    exit(0);
    }
    int theref = var_rett(name_of_var);

	if(theref == 1)
	{
        std::cout << "error";
		exit(0);
	}
	
	if(theref == 0)
	{
		map[name_of_var] = number;
	}
    
	name_of_var = "";
         
	number = 0;
    return;
 
}

void floats_dec(std::string content,int count)
{
    std::string var_name = "";
	int j =count;
	int i = count;
	int count1 = 0;
	if(content[i] != ' ')
	{ 
		std::cout << "error"<<std::endl;
		exit(0);
	}
	while(content[i] == ' ')
	{
		++i;
	}	
	flo_var(content,i);
	
	return;
}

void flo_var(std::string content ,int i )
{
    std::string varib_name ="";
	int count = 0;
	int number  = 0;
	while(content[i] >= 97 && content[i] <= 122)
	{
    	varib_name += content[i]; 
		++i;
		++count;
	}
	
	if(count < 2 )
	{
        std::cout <<" type error " <<std::endl;
		exit(0);
	}
	count = 0;

	while(content[i] == ' ')
	{
		++i;
	}
	if(content[i] == ';')
	{	
		return;
	}
	
	if(content[i] != '=')
	{
		std::cout << "error  = :"<<std::endl;
		exit(0);
	}
    
	++i;
    
	while(content[i] == ' ')
	{
        ++i;
    }
    
	while(content[i] >= 48 && content[i] <= 57 )
	{
	    number = number *10;
	    number += (content[i] - 48);
	    ++i;
	    ++count;
	}

    if(count == 0)
	{
	    std::cout << "error value "<<std::endl;
	    exit(0);
    }
    
	count = 0;
    while(content[i] == ' ' )
	{
	    ++i;
    }/////////////////////////////////
    int count1= 0;
    int number2 =0;
     
    if(content[i] == '+' || content[i] == '-' || content[i] == '*' || content[i] == '/' || content[i] == '%')
	{
      	++count1;
     	char  c = content[i];
     	++i;
    	if(count1 == 1)
		{
         	while(content[i] == ' ')
			{
             	++i; 
         	}
         	while(content[i] >= 48 && content[i] <= 57 )
			{
	     		number2 = number2 *10;
	     		number2 += (content[i] - 48);
	     		++i;
	     		++count;
	
	    	}
	  
     		if(count == 0)
			{
	     		std::cout << "error value "<<std::endl;
	     		exit(0);
     		}
       		int  valuee =  math_ops(number,number2,c);
       		number = valuee;  
     	}
    } 
    while(content[i] == ' ')
	{
        ++i;
    }
     
     ///////////////////////////////
    if(content[i] != ';' )
	{
	    std::cout << "error: you haven't entered the ; symbol" << std::endl;
	    exit(0);
    }
    int there  = var_rett(varib_name);

	if(there == 1)
	{
        std::cout << "error";
		exit(0);
	}
	
	if(there == 0)
	{
		map[varib_name] = number;
	}
    
	varib_name = "";
	number = 0;
    return;
}
void strings(std::string content,int count)
{
    std::string var_name = "";
	int j =count;
	int i = count;
	int count1 = 0;
	if(content[i] != ' ')
	{ 
		std::cout << "error"<<std::endl;
		exit(0);
	}
	while(content[i] == ' ')
	{
		++i;
	}	
	
	str_var(content,i);
	
	return;
}

void integer(std::string content,int count)
{
    std::string var_name = "";
	int j =count;
	int i = count;
	int count1 = 0;
	if(content[i] != ' ')
	{ 
		std::cout << "error"<<std::endl;
		exit(0);
	}
	while(content[i] == ' ')
	{
		++i;
	}	
	var_types(content,i);
	
	return;
}

void var_types(std::string content ,int i)
{
	std::string varib_name ="";
	int count = 0;
	int number  = 0;
	while(content[i] >= 97 && content[i] <= 122)
	{
    	varib_name += content[i];
		++i;
		++count;
	}
	if(count < 2 )
	{
        std::cout <<" type error" <<std::endl;
		exit(0);
	}
	count = 0;

	while(content[i] == ' ')
	{
		++i;
	}
	if(content[i] == ';')
	{	
		return;
	}
	if(content[i] != '=')
	{
		std::cout << "error  = :"<<std::endl;
		exit(0);
	}
    ++i;
    while(content[i] == ' ')
	{
        ++i;
    }
    while(content[i] >= 48 && content[i] <= 57 )
	{
	     number = number *10;
	     number += (content[i] - 48);
	     ++i;
	     ++count;
	    }

    if(count == 0)
	{
	    std::cout << "error value "<<std::endl;
	    exit(0);
    }
    count = 0;
    while(content[i] == ' ' )
	{
	    ++i;
    }/////////////////////////////////
    int count1= 0;
    int number2 =0;
     
    if(content[i] == '+' || content[i] == '-' || content[i] == '*' || content[i] == '/' || content[i] == '%')
	{
      	++count1;
     	char c = content[i];
     	++i;
     	if(count1 == 1)
		{
         	while(content[i] == ' ')
			{
             	++i; 
         	}
         	while(content[i] >= 48 && content[i] <= 57 )
			{
	     		number2 = number2 *10;
	     		number2 += (content[i] - 48);
	     		++i;
	     		++count;
			}
	  
     		if(count == 0)
			{
	     		std::cout << "error value "<<std::endl;
	     		exit(0);
     		}
       		int  valuee =  math_ops(number,number2,c);
       		number = valuee;  
     	}
    } 
    while(content[i] == ' ')
	{
        ++i;
    }
     
     ///////////////////////////////
    if(content[i] != ';' )
	{
	    std::cout << "error: you haven't entered the ; symbol" << std::endl;
	    exit(0);
    }
    int there  = var_rett(varib_name);

	if(there == 1)
	{
        std::cout << "error ";
		exit(0);
	}
	if(there == 0)
	{
		map[varib_name] = number;
	}
        varib_name = "";
	 	number = 0;
    	
		return;

}
void str_var(std::string content ,int i)
{    
    std::string str1 = "";
	std::string varibs_name ="";
	int count = 0;
	int number  = 0;
	while(content[i] >= 97 && content[i] <= 122)
	{
        varibs_name += content[i];  
		++i;
		++count;
	}
	if(count < 2 )
	{
        std::cout <<" type error " <<std::endl;
		exit(0);
	}
	count = 0;

	while(content[i] == ' ')
	{
		++i;
	}
	if(content[i] == ';')
	{	
		return;
	}
	if(content[i] != '=')
	{
		std::cout << "error  = :"<<std::endl;
		exit(0);
	}
    ++i;
    while(content[i] == ' ')
	{
        ++i;
    }
            
	if(content[i] != '\'')
	{
        std::cout << "error";
        exit(0);
    }
    ++i;
    
	while(content[i] != '\''  )
	{
	 	str1 +=content[i];
	 	++i;
	    ++count;
	}  
	while(content[i] != '\'')
	{
	    std::cout << "error '\''" << std::endl;
	    exit(0);
	}
	++i;
	while(content[i] == ' ')
	{
		++i;
	}
	
     count = 0;

    if(content[i] != ';' )
	{
	    std::cout << "error: you haven't entered the ; symbol " << std::endl;
	    exit(0);
    }
     
    int ret_var  = var_rett(varibs_name);

	if(ret_var == 1)
	{
        std::cout << "error";
		exit(0);
	}
	if(ret_var == 0)
	{
		sec_map[varibs_name] = str1;
	}
        varibs_name = "";
		number = 0;
    	return;

}


int var_rett(std::string str)
{
 	if(map.count(str) == 2)
	{
     std::cout << "error";
 	}
	if(map.count(str) == 1)
	{
		return 1;
	}

    else if( sec_map.count( str ) == 1 )
    {
        return 1;
    }     
    else
	{
    return 0;
	}
}

int math_ops(int number,int number2,char c)
{
    if(c == '+')
	{
        number += number2; 
        return number;
    }
    if(c == '-')
	{
        number -= number2;
        return number;
    }
    if(c == '*')
	{
        number *= number2;
        return number;
    }
    if(c == '/')
	{
        number /=number2;
        return number;
    }
    if(c == '%')
	{
        number %=number2;
        return number;
    }
    
    return number;
}
