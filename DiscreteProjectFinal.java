//Sujin Kim
//Discrete Math Project
//Title: Secret Message Translator


import java.util.Scanner; //Need for Scanner class
/**
 *
 * @author Admin
 */
public class DiscreteProject 
{

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) 
    {
        int mainChoice;
        final int SHIFT = 3;
        String text, cipher;
        
       Scanner keyboard = new Scanner (System.in);
       
       do{
           
       displayMainMenu();
       
       mainChoice = keyboard.nextInt();
        keyboard.nextLine(); //returns true if and only if this scanner has another line of input
       
       switch(mainChoice)
		{
                  case 1:
                        System.out.print("\nEnter The Message to EnCrypt: ");
                        text = keyboard.nextLine();
                        String encryptedMsg = encryptMessage(text,SHIFT).toString();
                        System.out.println("Secret Message: " + encryptedMsg);
                        
                    break;
                      
                  case 2:
                        System.out.println("\nEnter The Message to Decrypt: ");
                        cipher = keyboard.nextLine();
                        
                        String decryptedMsg =decryptMessage(cipher,26-SHIFT).toString();
                        
			System.out.println("Decrypted Mssage: " + decryptedMsg);
			
                    break;
                      
                  case 3:
                    
                    break;
                }
        }while (mainChoice != 3);
    }
    
    //displayMainMenu method displays main menu options
	public static void displayMainMenu()     
	{      
                System.out.println("=================================================================================");
                System.out.println("|Sujin's Secret Message Translator| ");
                System.out.println("-This Program will encrypt and decrypt message by using Caesar Cipher technique-");
		System.out.println("1. Encrypt Message");
		System.out.println("2. Decrypt Message");
                System.out.println("3. Exit the Program");
                System.out.print("Press 1,2 or 3 to Exit the Program: ");
		
	}
        
        public static StringBuffer encryptMessage(String text, int s)
            {
                 StringBuffer result= new StringBuffer();

            for (int i=0; i<text.length(); i++)
            {
                if (Character.isUpperCase(text.charAt(i)))
                {
                    char ch = (char)(((int)text.charAt(i) +
                                      s - 65) % 26 + 65);
                    result.append(ch);
                }
                else if (Character.isLowerCase(text.charAt(i)))
                {
                    char ch = (char)(((int)text.charAt(i) +
                                      s - 97) % 26 + 97);
                    result.append(ch);
                }
                else if (Character.isWhitespace(text.charAt(i)))
                {
                    char ch = ' ';
                    result.append(ch);
                }
                else
                {
                    char ch = text.charAt(i);
                    result.append(ch);
                }

            }
            return result;
        }
        
        public static StringBuffer decryptMessage(String cipher, int s)
        {
        
             StringBuffer result= new StringBuffer();

            for (int i=0; i<cipher.length(); i++)
            {
                if (Character.isUpperCase(cipher.charAt(i)))
                {
                    char ch = (char)(((int)cipher.charAt(i) +
                                      s - 65) % 26 + 65);
                    result.append(ch);
                }
                else if (Character.isLowerCase(cipher.charAt(i)))
                {
                    char ch = (char)(((int)cipher.charAt(i) +
                                      s - 97) % 26 + 97);
                    result.append(ch);
                }
                
                 else if (Character.isWhitespace(cipher.charAt(i)))
                {
                    char ch = ' ';
                    result.append(ch);
                }
                else
                {
                    char ch = cipher.charAt(i);
                    result.append(ch);
                }

            }
            return result;
        }
}
