from textblob import TextBlob



f=open('Sentiments.txt','r')
writefile=open('finalReview.txt','w')

#def get_sentiments(text,writefile):
for review in f.readlines():  
    y=review  
    polarity=TextBlob(y).sentiment.polarity
    if polarity >= 0.3 and polarity<=1:
        writefile.write("Good\n")
    elif polarity >=0 and  polarity <0.3 :
        writefile.write("Average\n")
    elif polarity >=-0.5 and  polarity <0 :
        writefile.write("Poor\n")
    else:
        writefile.write("Worst\n")
        
        
f.close()  
writefile.close()